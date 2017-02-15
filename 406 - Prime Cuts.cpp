#include <stdlib.h>
#include <stdio.h>
#define MAX 100000

bool prime[MAX];
int primetable[MAX], num = 0;

/* ���D��1�]����� */
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
        if (i % 2 == 0) {  // 1~N���������ƭӽ��(�]�t1�MN)
            P = C * 2;
            left = i / 2 + 1 - C;

            /* �n�L�X�Ӫ���ƶW�L1~N�����A������1~N��������Ƴ��L�X�� */
            if (P > i) {
                for (index = 1; index <= i; index++)
                    printf(" %d", primetable[index]);
                printf("\n");
            }
            /* ���}�l�L���_�I�A�æL�XP = C * 2 �ӽ�� */
            else {
                for (j = left, index = 1; index <= P; index++, j++)
                    printf(" %d", primetable[j]);
                printf("\n");
            }
        }
        else {  // 1~N�������_�ƭӽ��(�]�t1�MN)
            P = C * 2 - 1;
            center = i / 2 + 1;

            /* �n�L�X�Ӫ���ƶW�L1~N�����A������1~N��������Ƴ��L�X�� */
            if (P > i) {
                for (index = 1; index <= i; index++)
                    printf(" %d", primetable[index]);
                printf("\n");
            }
            /* ���}�l�L���_�I�A�æL�XP = C * 2 - 1 �ӽ�� */
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
