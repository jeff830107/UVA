#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    int num, i;
    int destination[500001], source[500001];
    bool YES;

    while ( scanf("%d", &num) && num != 0 ) {
        memset(destination, 0, sizeof(destination));
        memset(source, 0, sizeof(source));
        for (i = 0; i < num; i++)
            scanf("%d %d", &source[i], &destination[i]);

        if (num % 2 != 0) {
            cout << "NO\n";
            continue;
        }

        YES = true;
        for (i = 0; i < num; i++) {
            /*                                                                                           *
             * If the number users input is bigger than 500000,                                          *
             * it will be out of the range of the array, but still smaller than the upper bound of int   *
             *                                                                                           *
             *                      -> this method is Wrong!!                                            *
             *                                                                                           */
            if ( destination[ destination[ source[i] ] ] != source[i]) {
                YES = false;
                break;
            }
        }
        if (YES)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
