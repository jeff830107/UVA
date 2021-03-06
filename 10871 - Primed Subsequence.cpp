#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

int table[MAX], primetable[MAX], num;

/* make the primetable offline */
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

    /* 將篩中的所有質數放入primetable[]中 */
    for (i = 2, num = 0; i <= MAX; i++)
        if (table[i])
            primetable[++num] = i;
}

int main()
{
    int t, arr[MAX], last, length, data, x, i, j, temp, anti, sum;

    make_prime();

    scanf("%d", &t);
    while (t--) {
        /* initialization */
        for (i = 0; i < MAX; i++)
            arr[i] = 0;
        data = 0;
        anti = 1;
        last = -1;

        /* read in the data */
        scanf("%d", &data);
        for (i = 0; i < data; i++) {
            scanf("%d", &x);
            arr[++last] = x;
        }

        /* process */
        for (length = 2; length <= data; length++) {  /* increase the length of the subsequence if fail in this length */
            for (i = 0; i <= data - length; i++) {    /* finding the sum of each group and check if it is prime */
                sum = 0;
                for (j = 1, temp = i; j <= length; j++, temp++)  /* count the sum */
                    sum += arr[temp];
                for (j = 1; j <= num; j++)
                    if (sum == primetable[j]) {  /* if the sum of this case is prime */
                        anti = 0;
                        break;
                    }
                if (anti == 0)  /* break */
                    break;
            }
            if (anti == 0)  /* break */
                break;
        }

        /* print the result */
        if (anti == 1)
            printf("This sequence is anti-primed.\n");
        else {
            printf("Shortest primed subsequence is length %d:", length);
            for (j = 1; j <= length; j++, i++)
                printf(" %d", arr[i]);
            printf("\n");
        }

    }

    return 0;
}
