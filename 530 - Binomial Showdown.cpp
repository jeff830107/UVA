#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int n, k, a, b;
    scanf("%lld %lld", &n, &k);

    while ( !(n == 0 && k == 0) ) {

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

        printf("%lld\n", a);

        scanf("%lld %lld", &n, &k);
    }

    return 0;
}
