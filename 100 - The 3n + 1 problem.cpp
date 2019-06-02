#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int n, a, b, i, cnt, MAX;

    while ( scanf("%d %d", &a, &b) != EOF ) {
        /* a may be bigger than b */
        for (MAX = 0, i = min(a , b); i <= max(a , b); i++) {
            n = i;
            cnt = 1;
            while (n != 1) {
                if (n % 2 == 1)
                    n = 3 * n + 1;
                else
                    n = n / 2;
                cnt++;
            }
            if (cnt > MAX)
                MAX = cnt;
        }
        printf("%d %d %d\n", a, b, MAX);
    }

    return 0;
}
