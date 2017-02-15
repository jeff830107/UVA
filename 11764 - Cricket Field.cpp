#include <stdlib.h>
#include <stdio.h>

int main() {

    int i, j, cases, num, H, L;
    int a[50];

    scanf("%d", &cases);
    for (i = 1; i <= cases; i++) {

        printf("Case %d: ", i);

        scanf("%d", &num);
        for (j = 0; j < num; j++)
            scanf("%d", &a[j]);

        if (num == 1)
            printf("0 0\n");
        else {
            H = L = 0;
            for (j = 1; j < num; j++) {
                if (a[j] - a[j-1] > 0)
                    H++;
                else if (a[j] - a[j-1] < 0)
                    L++;
            }
            printf("%d %d\n", H, L);
        }
    }

    return 0;
}
