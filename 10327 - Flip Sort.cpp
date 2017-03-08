#include <stdlib.h>
#include <stdio.h>

int main() {

    int Number, i, j, temp, cnt;
    int input[1000];

    while (scanf("%d", &Number) != EOF) {
        for (i = 0; i < Number; i++) {
            scanf("%d", &input[i]);
        }
        cnt = 0;
        // Bubble Sort : Put the biggest number to the last of the queue
        for (i = Number; i > 0; i--) {
            for (j = 0; j < i-1; j++) {
                if (input[j] > input[j+1]) {
                    temp = input[j];
                    input[j] = input[j+1];
                    input[j+1] = temp;
                    cnt++;
                }
            }
        }
        printf("Minimum exchange operations : %d\n", cnt);
    }

    return 0;
}
