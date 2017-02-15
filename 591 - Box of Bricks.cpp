#include <iostream>
#include <stdlib.h>
#include <stdio.h>

int main() {

    int avg, n, i, moves, cnt;
    int arr[60];

    scanf("%d", &n);

    cnt = 1;
    while (n != 0) {
        for (avg = 0, i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            avg += arr[i];
        }
        avg /= n;
        for (moves = 0, i = 0; i < n; i++) {
            if (arr[i] > avg) {
                moves += arr[i] - avg;
            }
        }
        printf("Set #%d\n", cnt++);
        printf("The minimum number of moves is %d.\n", moves);
        printf("\n");   // a blank line between SETs

        scanf("%d", &n);
    }
}
