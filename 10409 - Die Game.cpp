#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int cmd, N, E, W, S, T, D, tmp;
    char buffer;
    char direction[10];

    while ( scanf("%d", &cmd) && cmd != 0 ) {
        scanf("%c", &buffer);

        /* initialization */
        N = 2, E = 4, W = 3, S = 5, T = 1, D = 6;
        while (cmd--) {
            gets(direction);
            if (direction[0] == 'n')  /* roll to North */
                tmp = T, T = S, S = D, D = N, N = tmp;
            else if (direction[0] == 'e')  /* roll to East */
                tmp = T, T = W, W = D, D = E, E = tmp;
            else if (direction[0] == 'w')  /* roll to West */
                tmp = T, T = E, E = D, D = W, W = tmp;
            else if (direction[0] == 's')  /* roll to South */
                tmp = T, T = N, N = D, D = S, S = tmp;
        }
        /* Output the number on the top */
        cout << T << endl;
    }

    return 0;
}
