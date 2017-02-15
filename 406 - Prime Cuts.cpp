#include <stdlib.h>
#include <stdio.h>
#define MAX 100000

bool prime[MAX];
int primetable[MAX], num = 0;

/* 此題把1也當成質數 */
void make() {
    int i, j;

    for (i = 1; i < MAX; i++)
        prime[i] = true;
    for (i = 2; i < MAX; i++)
        if (prime[i])
            for (j = 2; j*i <= MAX; j++)
                prime[j*i] = false;
    for (i = 1; i <= MAX; i++)
        if (prime[i])
            primetable[++num] = i;
}

int main() {
    int N, C, i, j, P, center, left, index;

    make();

    while (scanf("%d %d", &N, &C) != EOF) {

        for (i = 1; ; i++)
            if (primetable[i] > N)
                break;
        i--;

        printf("%d %d:", N, C);
        if (i % 2 == 0) {  // 1~N之間有偶數個質數(包含1和N)
            P = C * 2;
            left = i / 2 + 1 - C;

            /* 要印出來的質數超過1~N之間，直接把1~N之間的質數都印出來 */
            if (P > i) {
                for (index = 1; index <= i; index++)
                    printf(" %d", primetable[index]);
                printf("\n");
            }
            /* 找到開始印的起點，並印出P = C * 2 個質數 */
            else {
                for (j = left, index = 1; index <= P; index++, j++)
                    printf(" %d", primetable[j]);
                printf("\n");
            }
        }
        else {  // 1~N之間有奇數個質數(包含1和N)
            P = C * 2 - 1;
            center = i / 2 + 1;

            /* 要印出來的質數超過1~N之間，直接把1~N之間的質數都印出來 */
            if (P > i) {
                for (index = 1; index <= i; index++)
                    printf(" %d", primetable[index]);
                printf("\n");
            }
            /* 找到開始印的起點，並印出P = C * 2 - 1 個質數 */
            else {
                for (j = center - C + 1, index = 1; index <= P; index++, j++)
                    printf(" %d", primetable[j]);
                printf("\n");
            }
        }

        printf("\n");
    }

    return 0;
}
