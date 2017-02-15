#include <stdlib.h>
#include <stdio.h>
#define MAX 201

int node[MAX][MAX], color[MAX], last[MAX], bi, n;

void dfs(int index) {
    for (int i = 0; i < last[index]; i++) {
        if (color[ node[index][i] ] < 0) {  /* 如果下一個節點沒上過色 */
            color[index] == 0 ? color[ node[index][i] ] = 1 : color[ node[index][i] ] = 0;  /* 則塗上與現在這個節點相反的顏色 */
            dfs( node[index][i] );  /* 並前往下一個節點 */
        }
        /* 下一個節點上過色了 */
        if (color[ node[index][i] ] == color[index]) {  /* 檢查兩者顏色是否相同 */
            bi = 0;
            return;  /* 相同，則跳出dfs搜尋並印出結果 */
        }
        /* 不同，則繼續找下一個與現在這個節點相鄰的點 */
    }
    return;
}

int main()
{
    int m, a, b;

    scanf("%d", &n);
    while (n != 0) {
        /* initialization */
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++)
                node[i][j] = -1;
            last[i] = 0;
            color[i] = -1;
        }

        scanf("%d", &m);
        while (m--) {  /* 記錄相鄰關係 */
            scanf("%d %d", &a, &b);
            node[a][ last[a]++ ] = b;
            node[b][ last[b]++ ] = a;
        }

        bi = 1;
        color[0] = 0;  /* 找一個節點當起始點並上色 */
        dfs(0);  /* 進入dfs搜尋 */

        if (bi == 0)
            printf("NOT BICOLORABLE.\n");
        else
            printf("BICOLORABLE.\n");

        scanf("%d", &n);
    }

    return 0;
}
