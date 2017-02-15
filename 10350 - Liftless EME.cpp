#include <stdlib.h>
#include <stdio.h>

int main () {
    int n, m, total, arr[2000][20], i, j;
    char name[20];

    while (fgets(name, 20, stdin) != NULL) {
        scanf("%d %d", &n, &m);
        total = m * (n-1);
        for(i = 0; i < total; i++)
            for (j = 0; j < m; j++)
                scanf("%d", &arr[i][j]);

        printf("%s", name);
    }

    return 0;
}
