#include <stdlib.h>
#include <stdio.h>

struct node {
    int key, step;
};

node queue[100000];
bool prime[10000];

void prime_table() {

    int i, j, k;

    for (i = 2; i <= 10000; i++)
        prime[i] = true;

    for (i = 2; i <= 10000; i++) {
        if (prime[i]) {
            for (j = 2; j * i <= 10000; j++)
                prime[j * i] = false;
        }
    }
}

int change(int n, int i, int j) {

    switch (i) {
        case 1:
            return ( (n / 10) * 10 + j );
        case 2:
            return ( (n / 100) * 100 + j * 10 + n % 10 );
        case 3:
            return ( (n / 1000) * 1000 + j * 100 + n % 100 );
        case 4:
            return ( j * 1000 + n % 1000 );
    }
}

int main()
{
    int times, a, s[10000], top, bottom, x, y, ans, i, j, key, step;

    scanf("%d", &times);

    prime_table();

    for (a = 1; a <= times; a++) {
        scanf("%d %d", &x, &y);

        top = bottom = 1;
        ans = -1;
        queue[top].key = x;
        queue[top].step = 0;

        /* 初始化各個質數的最短路徑，方法為將其最短路徑都設一個很大的數 */
        for (i = 0; i < 10000; i++)
            s[i] = 100;

        while (1) {
            if (queue[top].key == y) {  /* 當x==y時，跳離開 */
                ans = queue[top].step;
                break;
            }

            for (i = 1; i <= 4; i++) {
                for (j = 0; j <= 9; j++) {
                    if (i == 4 && j == 0)  /* 如果想把千位數換成0，繼續跑迴圈 */
                        continue;
                    else                   /* 不然就進行數字代換 */
                        key = change(queue[top].key, i, j);

                    /* 代表已經成功數字代換 */

                    if (!prime[key]) /* 如果是合數，繼續跑迴圈 */
                        continue;

                    /* 代表交換後得到的key已經確認是質數了 */

                    step = queue[top].step + 1;  /* 到這點的路徑為 -> 之前所累積的距離 + 1 */

                    if (step >= s[key])  /* 如果得到的路徑不是最短路徑，繼續跑迴圈 */
                        continue;

                    if (key == y) {
                            ans = step;
                            break;
                        }

                    /* 代表得到的路徑是最短路徑，就把key跟step(路徑長)放進queue裡 */

                    s[key]= step;  /* !!!!!!!剛剛沒寫到這行!!!!!! */
                    bottom++;
                    queue[bottom].key = key;
                    queue[bottom].step = step;
                }
                if (queue[bottom].key == y)
                    break;
            }  /* 已完成這個level的探測 */

            if (top == bottom || ans >= 0) {  /* queue裡是空的，或是已經找到答案，則跳出迴圈 */
                break;
            }

            top++;
        }

        if (ans >= 0)
            printf("%d\n", ans);
        else
            printf("Impossible\n");

    }

    return 0;
}
