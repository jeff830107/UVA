#include <stdlib.h>
#include <stdio.h>
#define MAX 1001  /* �r�ꤺ�̦h1000�Ӧr�� */

int main()
{
    int alpha1[26] = {0}, alpha2[26] = {0}, nmin;
    char a[MAX], b[MAX];

    /* gets���פ����n��NULL�Ӥ��OEOF!! */
    while ( gets(a) != NULL ) {
        /* �s�p�g�^��r��a~z�b�r��@�X�{������ */
        for (int i = 0; a[i] != '\0'; i++)
            if (a[i] >= 97 && a[i] <= 122)
                alpha1[ a[i] - 97 ]++;

        gets(b);
        /* �s�p�g�^��r��a~z�b�r��G�X�{������ */
        for (int i = 0; b[i] != '\0'; i++)
            if (b[i] >= 97 && b[i] <= 122)
                alpha2[ b[i] - 97 ]++;

        /* ���Ӧr�����ǦL�X���� */
        for (int i = 0; i < 26; i++) {
            if (alpha1[i] > 0 && alpha2[i] > 0) {
                if (alpha1[i] > alpha2[i])
                    nmin = alpha2[i];
                else
                    nmin = alpha1[i];

                while (nmin--)
                    printf("%c", i + 97);
            }
        }
        printf("\n");
        /* initialization */
        for (int i = 0; i < 26; i++)
            alpha1[i] = alpha2[i] = 0;
    }

    return 0;
}
