#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int co, i, d, first;

    i = -1;
    while ( (scanf("%d", &co) != EOF) || i != -1 ) {
        d = 0;

        if (i == -1) {
            i = 8;
            first = 0;
        }

        if (co != 0) {
            if (first == 0 && i == 1) {
                if (co == 1)
                    printf("x");
                else if (co > 1)
                    printf("%dx", co);
                else {
                    d = d - co;
                    if (d == 1)
                        printf("-x");
                    else
                        printf("-%dx", d);
                }
                first = 1;
            }
            else if (first == 0 && i > 1) {  /* �|���������X�{�B���������`�ƶ��]�����@����*/
                if (co == 1)
                    printf("x^%d", i);
                else if (co < 0) {
                    d = d - co;
                    if (d == 1)
                        printf("-x^%d", i);
                    else
                        printf("-%dx^%d", d, i);

                }
                else
                    printf("%dx^%d", co, i);
                first = 1;
            }
            else if (first == 0 && i == 0) {  /* �|���������X�{�A���O�������`�ƶ�  */
                printf("%d", co);
                first = 1;
            }
            else {                            /* �w�g�������X�{�L�F  */
                if (i == 0) {  /* �b�`�ƶ��� */
                    if (co > 0)
                        printf(" + %d", co);
                    else {
                        d = d - co;
                        printf(" - %d", d);
                    }
                }
                else if (i == 1) {  /* �b�@������ */
                    if (co > 1)
                        printf(" + %dx", co);
                    else if (co == 1)
                        printf(" + x");
                    else {
                        d = d - co;
                        printf(" - %dx", d);
                    }
                }
                else if (co == 1)
                    printf(" + x^%d", i);
                else if (co > 1) {
                    printf(" + %dx^%d", co, i);
                }
                else {   /* �Y�� < 0 */
                    d = d - co;
                    if (d == 1)
                        printf(" - x^%d", i);
                    else
                        printf(" - %dx^%d", d, i);
                }
            }
        }
        else {
            if (i == 0 && first == 0)  /* ��������0 */
                printf("0");
        }

        if (i == 0)
            printf("\n");

        i--;
    }

    return 0;
}
