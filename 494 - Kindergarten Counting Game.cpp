#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

    char a[1000];
    int flag, cnt, i, length;

    while ( gets(a) != NULL ) {
        flag = 0;
        length = strlen(a);
        cnt = 0;
        for (i = 0; i < length; i++) {
            if ( (a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z') ) {
                if (!flag) {
                    flag = 1;
                    cnt++;
                }
            }
            else
                if (flag)
                    flag = 0;
        }
        printf("%d\n", cnt);
    }

    return 0;
}
