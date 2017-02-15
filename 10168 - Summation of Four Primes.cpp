#include <stdlib.h>
#include <stdio.h>
#define MAX 10000000

int table[MAX], primetable[MAX], num;

void make_prime() {
    int i, j;

    /* ��l�ɡA�Ҧ��Ƴ��b�z�� */
    for (i = 2; i <= MAX; i++)
        table[i] = true;

    /* �Ni�����Ʊq�z���z�h */
    for (i = 2; i <= MAX; i++)
        if (table[i]) {
            for (j = 2; j*i <= MAX; j++)  /* j*i�N��i��j���A�ӧڭ̱qi���⭿�}�l�z�h */
                table[j*i] = false;
        }

    /* [���@�w�n��]�N�z�����Ҧ���Ʃ�Jprimetable[]�� */
    for (i = 2, num = 0; i <= MAX; i++)
        if (table[i])
            primetable[++num] = i;
}

int main()
{
    int n, a, b;

    make_prime();

    while (scanf("%d", &n) != EOF) {
        if (n >= 8) {
            if (n % 2 == 0) {
                n -= 4;
                printf("2 2 ");
            }
            else {
                n -= 5;
                printf("2 3 ");
            }
            for (int i = 1; i <= (num / 2) + 1; i++) {
                a = primetable[i];
                b = n - a;
                if (table[b] == true)
                    break;
            }

            printf("%d %d\n", a, b);
        }
        else
            printf("Impossible.\n");

    }

    return 0;
}
