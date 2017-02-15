#include <stdlib.h>
#include <stdio.h>

int main() {

    int cases, i;
    int a[10];
    int ascending, ordered;

    scanf("%d", &cases);
    printf("Lumberjacks:\n");
    while (cases--) {
        // Loading Input
        for (i = 0; i < 10; i++)
            scanf("%d", &a[i]);
        // Check ascending or descending
        if (a[0] - a[1] < 0)
            ascending = 1;
        else
            ascending = 0;
        // Assume ordered
        ordered = 1;
        // Check whether always ascending
        if (ascending == 1) {
            for (i = 2; i < 10; i++) {
                if (a[i-1] - a[i] > 0) {
                    ordered = 0;
                    break;
                }
            }
        }
        // Check whether always descending
        else {
            for (i = 2; i < 10; i++) {
                if (a[i-1] - a[i] < 0) {
                    ordered = 0;
                    break;
                }
            }
        }
        if (ordered)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }

    return 0;
}
