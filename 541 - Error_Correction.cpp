#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n, element, row_type, column_type, x, y;
    int row[100];  /* 方向是由左到右 */
    int column[100];  /* 方向是由上到下 */

    scanf("%d", &n);
    while (n != 0) {

        for (int i = 0; i < n; i++)
            row[i] = column[i] = 0;

        /* 讀矩陣 */
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
                    x = i;  /* 如果第一次出現奇數的行數，紀錄下來 */
                row_type++;
            }
            if (column[i] % 2 != 0) {
                if (column_type == 0)
                    y = i;  /* 如果第一次出現奇數的列數，紀錄下來 */
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
