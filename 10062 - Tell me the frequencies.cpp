#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

    char in[1005];
    int ASCII[129];
    int index, MAX, flag, i, j, length;

    flag = 0;
    while ( gets(in) != NULL ) {

        if (flag)
            printf("\n");
        for (i = 1; i < 129; i++)
            ASCII[i] = 0;

        length = strlen(in);
        for (i = 0; i < length; i++) {
            if (in[i] == '\n')
                break;
            index = (int)in[i];
            ASCII[index]++;
        }
        MAX = 0;
        for (i = 32; i < 129; i++)
            if (MAX < ASCII[i])
                MAX = ASCII[i];

        for (i = 1; i <= MAX; i++) {
            for (j = 128; j >= 32; j--) {
                if (ASCII[j] == i)
                    printf("%d %d\n", j, i);
            }
        }
        flag = 1;
        memset(in, 0, sizeof(in));
    }

    return 0;
}
