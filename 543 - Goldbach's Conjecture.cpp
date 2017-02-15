#include <stdlib.h>
#include <stdio.h>
#define MAX 1000000

int table[MAX], primetable[MAX], num;

void make_prime() {
    int i, j;

    /* ﹍┮Τ计常縵い */
    for (i = 2; i <= MAX; i++)
        table[i] = true;

    /* 盢i计眖縵い縵 */
    for (i = 2; i <= MAX; i++)
        if (table[i]) {
            for (j = 2; j*i <= MAX; j++)  /* j*iijτи眖iㄢ秨﹍縵 */
                table[j*i] = false;
        }

    /* [ぃ﹚璶暗]盢縵い┮Τ借计primetable[]い */
    for (i = 2, num = 0; i <= MAX; i++)
        if (table[i])
            primetable[++num] = i;
}

int main()
{
    int n, a, b;

    make_prime();

    scanf("%d", &n);
    while (n != 0) {
        for (int i = 1; i <= (num / 2) + 1; i++) {
            a = primetable[i];
            b = n - a;
            if (table[b] == true)
                break;
        }
        if (table[b] == true)
            printf("%d = %d + %d\n", n, a, b);
        else
            printf("Goldbach's conjecture is wrong.\n");


        scanf("%d", &n);
    }

    return 0;
}
