#include <stdlib.h>
#include <stdio.h>
#define MAX 1000000

int table[MAX], primetable[MAX], num;

void make_prime() {
    int i, j;

    /* 初始時，所有數都在篩中 */
    for (i = 2; i <= MAX; i++)
        table[i] = true;

    /* 將i的倍數從篩中篩去 */
    for (i = 2; i <= MAX; i++)
        if (table[i]) {
            for (j = 2; j*i <= MAX; j++)  /* j*i代表i的j倍，而我們從i的兩倍開始篩去 */
                table[j*i] = false;
        }

    /* [不一定要做]將篩中的所有質數放入primetable[]中 */
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
