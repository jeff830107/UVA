#include <stdlib.h>
#include <stdio.h>
#include <queue>
#define MAX 33001

using namespace std;
queue<int> people;

int table[MAX], primetable[MAX], num;

void make_prime() {
    int i, j;

    for (i = 2; i <= MAX; i++)
        table[i] = true;

    for (i = 2; i <= MAX; i++)
        if (table[i]) {
            for (j = 2; j*i <= MAX; j++)
                table[j*i] = false;
        }

    for (i = 2, num = 0; i <= MAX; i++)
        if (table[i])
            primetable[++num] = i;
}

int main()
{
    int answer, i, s, n;

    make_prime();

    scanf("%d", &n);
    while (n != 0) {

        answer = 0;

        /* 網路上神解法... */
        for (s = 0, i = 1; i <= n; i++)
            s = (s + primetable[n-i+1]) % i;
        answer = s + 1;

        printf("%d\n", answer);

        scanf("%d", &n);
    }

    return 0;
}
