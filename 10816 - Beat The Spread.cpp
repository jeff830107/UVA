#include <stdlib.h>
#include <stdio.h>

int main() {
    int sum, dif, N;

    scanf("%d", &N);
    while (N--) {
        /*
         *  a + b = sum
         *  a - b = dif
         *  a = (sum + dif) / 2
         *  b = (sum - dif) / 2
         */
        scanf("%d %d", &sum, &dif);
        if (sum < dif)
            printf("impossible\n");
        else if ((sum + dif) % 2 != 0)
            printf("impossible\n");
        else
            printf("%d %d\n", (sum + dif) / 2, (sum - dif) / 2);
    }
}
