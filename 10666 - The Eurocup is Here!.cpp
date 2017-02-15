#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int M, N, X, total, i, j, best, worst, num, num1, temp, temp1;

    scanf("%d", &M);

    for (i = 1; i <= M; i++) {
        scanf("%d %d", &N, &X);

        total = 1;

        for (j = 1; j <= N; j++) {
            total = 2 * total;
        }

        best = 1;
        worst = total;
        num = 0;
        num1 = 1;

        for (j = 1, temp = X; j <= N; j++) {
            if (temp % 2 != 0) {
                while (temp != 1) {
                    temp1 = temp - 1;
                    while (temp1 % 2 == 0) {
                        temp1 = temp1 / 2;
                    }
                    num++;
                    temp = temp1;
                }
                num++;
                break;
            }
            else if (temp == 0) {
                worst = 1;
                break;
            }
            else {
                temp = temp / 2;
                worst = worst - num1;
                num1 = num1 * 2;
            }
        }

        best = best + num;
        printf("%d %d\n", best, worst);
    }
}
