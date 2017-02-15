#include <stdlib.h>
#include <stdio.h>
#define MAX 201

int node[MAX][MAX], color[MAX], last[MAX], bi, n;

void dfs(int index) {
    for (int i = 0; i < last[index]; i++) {
        if (color[ node[index][i] ] < 0) {  /* �p�G�U�@�Ӹ`�I�S�W�L�� */
            color[index] == 0 ? color[ node[index][i] ] = 1 : color[ node[index][i] ] = 0;  /* �h��W�P�{�b�o�Ӹ`�I�ۤϪ��C�� */
            dfs( node[index][i] );  /* �ëe���U�@�Ӹ`�I */
        }
        /* �U�@�Ӹ`�I�W�L��F */
        if (color[ node[index][i] ] == color[index]) {  /* �ˬd����C��O�_�ۦP */
            bi = 0;
            return;  /* �ۦP�A�h���Xdfs�j�M�æL�X���G */
        }
        /* ���P�A�h�~���U�@�ӻP�{�b�o�Ӹ`�I�۾F���I */
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
        while (m--) {  /* �O���۾F���Y */
            scanf("%d %d", &a, &b);
            node[a][ last[a]++ ] = b;
            node[b][ last[b]++ ] = a;
        }

        bi = 1;
        color[0] = 0;  /* ��@�Ӹ`�I��_�l�I�äW�� */
        dfs(0);  /* �i�Jdfs�j�M */

        if (bi == 0)
            printf("NOT BICOLORABLE.\n");
        else
            printf("BICOLORABLE.\n");

        scanf("%d", &n);
    }

    return 0;
}
