#include <stdlib.h>
#include <stdio.h>
#define MAX 1001  /* 字串內最多1000個字母 */

int main()
{
    int alpha1[26] = {0}, alpha2[26] = {0}, nmin;
    char a[MAX], b[MAX];

    /* gets的終止條件要用NULL而不是EOF!! */
    while ( gets(a) != NULL ) {
        /* 存小寫英文字母a~z在字串一出現的次數 */
        for (int i = 0; a[i] != '\0'; i++)
            if (a[i] >= 97 && a[i] <= 122)
                alpha1[ a[i] - 97 ]++;

        gets(b);
        /* 存小寫英文字母a~z在字串二出現的次數 */
        for (int i = 0; b[i] != '\0'; i++)
            if (b[i] >= 97 && b[i] <= 122)
                alpha2[ b[i] - 97 ]++;

        /* 按照字母順序印出答案 */
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
