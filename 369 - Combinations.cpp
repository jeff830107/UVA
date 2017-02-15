#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n, k, a, b, _k;
    scanf("%lld %lld", &n, &k);

    while ( !(n == 0 && k == 0) ) {

        _k = k;
        if (k > n / 2)
            k = n - k;

        a = b = 1;
        for (long long int i = 1; i <= k; i++) {
            a *= n - k + i;
            b *= i;

            if (a % b == 0) {
                a /= b;
                b = 1;
            }
        }

        printf("%lld things taken %lld at a time is %lld exactly.\n", n, _k, a);

        scanf("%lld %lld", &n, &k);
    }

    return 0;
}
