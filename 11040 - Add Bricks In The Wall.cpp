#include <stdlib.h>
#include <stdio.h>

int main () {
    int cases, arr[10][10], i, j, a, b, index;
    int x[10] = {0,2,4,6,2,4,6,4,6,6};
    int y[10] = {0,0,0,0,2,2,2,4,4,6};

    scanf("%d", &cases);
    while (cases--) {
        for (i = 1, a = 1; i <= 5; i++, a+= 2)
            for (j = 1, b = 1; j <= i; j++, b += 2)
                scanf("%d", &arr[a][b]);
        i = 3;
        j = 1;
        for (index = 0; index <= 9; index++) {
            a = i + x[index];
            b = j + y[index];
            arr[a][b+1] = (arr[a-2][b] - arr[a][b] - arr[a][b+2]) / 2;
            arr[a-1][b] = arr[a][b] + arr[a][b+1];
            arr[a-1][b+1] = arr[a][b+1] + arr[a][b+2];
        }

        for (i = 1; i <= 9; i++) {
            for (j = 1; j <= i; j++) {
                printf("%d", arr[i][j]);
                if (j != i)
                    printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}
