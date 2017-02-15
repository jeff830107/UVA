#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int y;
    double k, total, n;

    scanf("%d", &y);
    while (y != 0) {
        y -= 1960;
        y /= 10;

        k = 4.0;
        for (int i = 1; i <= y; i++)
            k *= 2.0;

        total = 0;
        for (n = 1; total <= k; n++)
            total += ( log(n) / log(2.0) );

        printf("%.f\n", n - 2.0);

        scanf("%d", &y);
    }

    return 0;
}
