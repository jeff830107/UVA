#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, n, x, big, small, ans;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        big = small = -1;
        while (n--) {
            scanf("%d", &x);
            if (big == -1 && small == -1)  /* first store */
                big = small = x;
            else {
                if (x > big)
                    big = x;
                if (x < small)
                    small = x;
            }
        }
        ans = 2 * (big - small);
        printf("%d\n", ans);
    }

    return 0;
}
