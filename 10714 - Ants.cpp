#include <stdlib.h>
#include <stdio.h>

int main()
{
    int n, length, number, min, max, r, l, ant;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &length, &number);

        min = max = 0;
        for (int j = 0; j < number; j++) {
            scanf("%d", &ant);
            r = length - ant;
            l = ant;

            if (l > r) {  /* 離右邊比較近 */
                if (r > min)
                    min = r;
                if (l > max)
                    max = l;
            }
            else {        /* 離左邊比較近 */
                if (l > min)
                    min = l;
                if (r > max)
                    max = r;
            }
        }

        printf("%d %d\n", min, max);

    }

    return 0;
}
