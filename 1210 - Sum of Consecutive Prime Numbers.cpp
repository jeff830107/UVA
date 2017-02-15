#include <stdio.h>
#include <stdlib.h>
#define MAX 10001

bool table[MAX];
int prime[MAX] = {0}, last;

void make() {
    int i, j;

    for (i = 2; i < MAX; i++)
        table[i] = true;
    for (i = 2; i < MAX; i++)
        for (j = 2; j*i < MAX; j++)
            if (table[j*i])
                table[j*i] = false;
    for (i = 2, j = 0; i < MAX; i++)
        if (table[i]) {
            prime[j] = i;
            j++;
        }
    last = j;  /* last指到最後一個質數的下一格 */
}

int main()
{
    int num, sum, ans;

    make();

    scanf("%d", &num);
    while (num != 0) {
        ans = 0;
        for (int i = 0; i < last && prime[i] <= num; i++) {  /* 當連續質數的第一個大於該數的話，代表測試結束，跳出迴圈 */
            sum = 0;
            sum += prime[i];
            if (sum != num) {
                for (int j = i+1; j < last && sum <= num; j++) {
                    sum += prime[j];
                    if (sum == num) {
                        ans++;
                        break;
                    }
                }
            }
            else
                ans++;
        }
        printf("%d\n", ans);

        scanf("%d", &num);
    }

    return 0;
}
