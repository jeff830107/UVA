#include <stdlib.h>
#include <stdio.h>

int table[40];

void Fib() {

    int i;

    table[0] = 1;
    table[1] = 2;
    for (i = 2; i < 40; i++)
        table[i] = table[i-2] + table[i-1];
}

int main() {

    int N, num, i, flag;

    Fib();

    scanf("%d", &N);
    while (N--) {
        scanf("%d", &num);
        printf("%d = ", num);

        flag = 0;
        for (i = 39; i >= 0; i--) {
            if (table[i] <= num) {
                if (flag == 0)
                    flag = 1;
                num -= table[i];
                printf("1");
            }
            else if (flag) {
                printf("0");
            }
        }
        printf(" (fib)\n");
    }

    return 0;
}
