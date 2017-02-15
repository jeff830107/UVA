#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int cases, n, d, i, sum;

    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);

        n = abs(n);
        i = sum = 0;
        d = 1;
        do {
            i++;
            sum += i;
            if (sum >= n)
                d = sum - n;
        } while (d % 2 != 0);
        printf("%d\n", i);
        /* 注意題目每組測資間需換行 */
        if (cases != 0)
            printf("\n");
    }

    return 0;
}
