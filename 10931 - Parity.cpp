#include <stdlib.h>
#include <stdio.h>
#define MAX 10000

int main () {
    int num, i, last, ans;
    int arr[MAX];

    scanf("%d", &num);
    while (num != 0) {
        ans = i = 0;
        while (num != 1) {
            arr[i++] = num % 2;
            num /= 2;
        }
        arr[i] = num;
        last = i;

        printf("The parity of ");
        for (i = last; i >= 0; i--) {
            printf("%d", arr[i]);
            if (arr[i])
                ans++;
        }
        printf(" is %d (mod 2).\n", ans);


        scanf("%d", &num);
    }

    return 0;
}
