#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n, element, row_type, column_type, x, y;
    int row[100];  /* ��V�O�ѥ���k */
    int column[100];  /* ��V�O�ѤW��U */

    scanf("%d", &n);
    while (n != 0) {

        for (int i = 0; i < n; i++)
            row[i] = column[i] = 0;

        /* Ū�x�} */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &element);
                if (element == 1) {
                    row[i]++;
                    column[j]++;
                }
            }
        }

        row_type = column_type = 0;
        for (int i = 0; i < n; i++) {
            if (row[i] % 2 != 0) {
                if (row_type == 0)
                    x = i;  /* �p�G�Ĥ@���X�{�_�ƪ���ơA�����U�� */
                row_type++;
            }
            if (column[i] % 2 != 0) {
                if (column_type == 0)
                    y = i;  /* �p�G�Ĥ@���X�{�_�ƪ��C�ơA�����U�� */
                column_type++;
            }

        }

        if (row_type == 0 && column_type == 0)
            printf("OK\n");
        else if (row_type == 1 && column_type == 1) {
            printf("Change bit (%d,%d)\n", x+1, y+1);
        }
        else {
            printf("Corrupt\n");
        }

        scanf("%d", &n);
    }

    return 0;
}
