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

        /* ��l�ƦU�ӽ�ƪ��̵u���|�A��k���N��̵u���|���]�@�ӫܤj���� */
        for (i = 0; i < 10000; i++)
            s[i] = 100;

        while (1) {
            if (queue[top].key == y) {  /* ��x==y�ɡA�����} */
                ans = queue[top].step;
                break;
            }

            for (i = 1; i <= 4; i++) {
                for (j = 0; j <= 9; j++) {
                    if (i == 4 && j == 0)  /* �p�G�Q��d��ƴ���0�A�~��]�j�� */
                        continue;
                    else                   /* ���M�N�i��Ʀr�N�� */
                        key = change(queue[top].key, i, j);

                    /* �N��w�g���\�Ʀr�N�� */

                    if (!prime[key]) /* �p�G�O�X�ơA�~��]�j�� */
                        continue;

                    /* �N��洫��o�쪺key�w�g�T�{�O��ƤF */

                    step = queue[top].step + 1;  /* ��o�I�����|�� -> ���e�Ҳֿn���Z�� + 1 */

                    if (step >= s[key])  /* �p�G�o�쪺���|���O�̵u���|�A�~��]�j�� */
                        continue;

                    if (key == y) {
                            ans = step;
                            break;
                        }

                    /* �N��o�쪺���|�O�̵u���|�A�N��key��step(���|��)��iqueue�� */

                    s[key]= step;  /* !!!!!!!���S�g��o��!!!!!! */
                    bottom++;
                    queue[bottom].key = key;
                    queue[bottom].step = step;
                }
                if (queue[bottom].key == y)
                    break;
            }  /* �w�����o��level������ */

            if (top == bottom || ans >= 0) {  /* queue�̬O�Ū��A�άO�w�g��쵪�סA�h���X�j�� */
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
