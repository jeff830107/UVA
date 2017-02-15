#include <stdlib.h>
#include <stdio.h>
#define MAX 50000

int root[MAX];
bool flag[MAX];

void make_root() {
    int i;

    /* Initialization: 1 -> 1, 2 -> 2, ... , so on */
    for (i = 0; i < MAX; i++) {
        root[i] = i;
        flag[i] = false;  /* haven't appeared */
    }
}

int find_root(int x) {
    if (x != root[x])
        root[x] = find_root(root[x]);
    return root[x];
}

void create_relation(int x, int y) {
    x = find_root(x);
    y = find_root(y);
    if (x == y)    /* points to itself(or become a cycle), ex: 1 2, 2 3, 3 1 */
        return;
    root[y] = x;
}

int main() {

    int x, y, cnt, i, first;
    bool tree;

    scanf("%d %d", &x, &y);
    cnt = 1;

    while (x >= 0 && y >= 0) {
        if (x == 0 && y == 0) {   /* for sample case4 */
            printf("Case %d is a tree.\n", cnt++);
            scanf("%d %d", &x, &y);
            continue;   /* go back to while loop */
        }

        make_root();

        tree = true;  /* assume TRUE */
        first = x;
        do {
            flag[x] = true;    // x appears
            flag[y] = true;    // y appears

            if ( find_root(x) == find_root(y) )   /* points to itself(or become a cycle), not a tree */
                tree = false;

            create_relation(x, y);

            scanf("%d %d", &x, &y);
        } while ( !(x == 0 && y == 0) );  /* if a == 0 and b == 0, it will break this do-while loop */

        for (i = 0; i < MAX; i++) {
            /* the reason we need to check flag[i] == 1 is that, if that number doesn't appear, we don't need to check it's root
             *
             * if the root of i is not equal to the root of first(or any other appeared number),
             * it means that there are at least two trees(at least two roots) */
            if ( flag[i] && find_root(i) != find_root(first)  ) {
                tree = false;
                break;
            }
        }

        if (tree)
            printf("Case %d is a tree.\n", cnt++);
        else
            printf("Case %d is not a tree.\n", cnt++);

        scanf("%d %d", &x, &y);
    }

    return 0;
}
