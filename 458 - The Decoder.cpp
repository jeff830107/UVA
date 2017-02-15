#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 9999

int main ()
{
    char c[MAX];

    while (gets(c) != NULL) {
        for (int i = 0; i < strlen(c); i++) {
            printf("%c", c[i] - 7);
        }
        printf("\n");
    }

    return 0;
}
