#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define MAX 10001

using namespace std;

vector<int> node[MAX];
int visit[MAX], sum;

void dfs(int start) {

    for (int i = 0; i < (int)node[start].size(); i++) {
        if (visit[ node[start][i] ] == 0) {
            visit[ node[start][i] ] = 1;
            sum++;
            dfs( node[start][i] );
        }
    }
    return;
}

int main()
{
    int cases, N, M, L, a, b, start;

    scanf("%d", &cases);
    while (cases--) {

        /* initialization */
        for (int i = 0; i < MAX; i++) {
            node[i].clear();
            visit[i] = 0;
        }
        sum = 0;

        scanf("%d %d %d", &N, &M, &L);
        /* ¬ö¿ý«e«á¶¶§Ç */
        while (M--) {
            scanf("%d %d", &a, &b);
            node[a].push_back(b);
        }
        /* ±À°©µPÅo~ */
        while (L--) {
            scanf("%d", &start);
            if (visit[start] == 0) {
                visit[start] = 1;
                sum++;
                dfs(start);
            }
        }
        printf("%d\n", sum);
    }

    return 0;
}
