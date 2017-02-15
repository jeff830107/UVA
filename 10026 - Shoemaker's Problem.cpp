#include <stdlib.h>
#include <stdio.h>
#define MAX 1001

int main()
{
    int cases, N, i, j;
    double task[MAX][2], sorting[2][MAX], temp;
    char buffer;

    scanf("%d", &cases);
    while (cases--) {

        scanf("%c", &buffer);
        scanf("%d", &N);
        /* read in the data */
        for (i = 0; i < N; i++) {
            scanf("%lf %lf", &task[i][0], &task[i][1]);
            sorting[0][i+1] = task[i][1] / task[i][0];
            sorting[1][i+1] = i+1;
        }
        /* selection sort */
        for (i = 2; i <= N; i++) {
            j = i;
             while (j > 1 && sorting[0][j] > sorting[0][j-1]){
                 /* sorting for the value */
                 temp = sorting[0][j];
                 sorting[0][j] = sorting[0][j-1];
                 sorting[0][j-1] = temp;
                 /* sorting for the index */
                 temp = sorting[1][j];
                 sorting[1][j] = sorting[1][j-1];
                 sorting[1][j-1] = temp;
                 j--;
             }
        }
        for (i = 1; i <= N; i++)
            /* no space for the last one */
	    /* 因為這邊試了超久...2次PE+1次WA */
            if (i == N)
                printf("%.lf", sorting[1][i]);
            else
                printf("%.lf ", sorting[1][i]);
        printf("\n");

        /* initialization */
        for (i = 0; i < MAX; i++)
            task[i][0] = task[i][1] = sorting[0][i+1] = sorting[1][i+1] = 0;

        /* blank line for two consecutive cases */
        if (cases != 0)
            printf("\n");

    }

    return 0;
}
