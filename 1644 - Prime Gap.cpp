#include <stdio.h>
#include <stdlib.h>
#define MAX 1299709

bool table[MAX];

void make() {
    int i, j;

    for (i = 2; i <= MAX; i++)
        table[i] = true;

    for (i = 2; i <= MAX; i++) {
        if (table[i]) {
            for (j = 2 ; j*i <= MAX ; j++)
                table[j*i] = false;
        }
    }

}

int main()
{
    int n;
    long long int r, l, length;

    make();

    scanf("%d", &n);
    while (n != 0) {

        if (table[n] == true)
            printf("0\n");
        else {
            /* ��k��Ĥ@�ӽ�� */
            for (long long int i = (long long int)n; table[i] != true;) {
                r = i;
                i = i + (long long int)1;
            }
            r = r + (long long int)1;

            /* �䥪��Ĥ@�ӽ�� */
            for (long long int i = (long long int)n; table[i] != true;) {
                l = i;
                i = i - (long long int)1;
            }
            l = l - (long long int)1;

            /* ��Z�� */
            length = r - l;
            printf("%ld\n", length);
        }

        scanf("%d", &n);
    }

    return 0;
}
