#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// In order to convert letters to numbers
int char2int(char a) {
    return (a-'0');
}

int main() {

    int CASE, i, j, x;
    char a[200], b[200], result[201];
    char c;
    int carry, tmp;
    int start;

    scanf("%d", &CASE);
    c = getchar();  // for the end of line occurs after the number of cases

    while (CASE--) {

        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(result, 0, sizeof(result));

        // store the former string
        c = getchar();
        i = 0;
        while (c != ' ') {
            a[i++] = c;
            c = getchar();
        }

        // store the latter string
        c = getchar();
        j = 0;
        while (c != '\n') {
            b[j++] = c;
            c = getchar();
        }

        // decide which one's length is bigger, the former or the latter

        if (i == j) {  // the former string's length is the same as the latter's
            i--;
            j--;

            carry = 0;
            for (x = 0; x <= i; x++) {
                tmp = char2int(a[x]) + char2int(b[x]) + carry;
                if (tmp > 9) {
                    result[x] = (tmp-10) + '0';
                    carry = 1;
                }
                else {
                    result[x] = tmp + '0';
                    carry = 0;
                }
            }
            if (carry == 1)
                result[++i] = '1';

            if (result[0] == '0')
                start = 0;
            else
                start = 1;

            x = 0;
            while (start == 0 && result[x] == '0')  // get rid of not necessary zeros
                x++;
            for (; x <= i; x++)
                printf("%c", result[x]);
            printf("\n");
        }
        else if (i > j) {  // the former string's length is bigger than the latter's
            i--;
            j--;

            carry = 0;
            for (x = 0; x <= i; x++) {
                if (x > j)
                    tmp = char2int(a[x]) + carry;
                else
                    tmp = char2int(a[x]) + char2int(b[x]) + carry;

                if (tmp > 9) {
                    result[x] = (tmp-10) + '0';
                    carry = 1;
                }
                else {
                    result[x] = tmp + '0';
                    carry = 0;
                }
            }

            if (carry == 1)
                result[++i] = '1';

            if (result[0] == '0')
                start = 0;
            else
                start = 1;

            x = 0;
            while (start == 0 && result[x] == '0')  // get rid of not necessary zeros
                x++;
            for (; x <= i; x++)
                printf("%c", result[x]);
            printf("\n");
        }
        else {  // the former string's length is smaller than the latter's
            i--;
            j--;

            carry = 0;
            for (x = 0; x <= j; x++) {
                if (x > i)
                    tmp = char2int(b[x]) + carry;
                else
                    tmp = char2int(a[x]) + char2int(b[x]) + carry;

                if (tmp > 9) {
                    result[x] = (tmp-10) + '0';
                    carry = 1;
                }
                else {
                    result[x] = tmp + '0';
                    carry = 0;
                }
            }

            if (carry == 1)
                result[++i] = '1';

            if (result[0] == '0')
                start = 0;
            else
                start = 1;

            x = 0;
            while (start == 0 && result[x] == '0')  // get rid of not necessary zeros
                x++;
            for (; x <= j; x++)
                printf("%c", result[x]);
            printf("\n");
        }
    }

    return 0;
}
