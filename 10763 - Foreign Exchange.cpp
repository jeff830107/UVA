#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

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

        sort(source, source + num);
        sort(destination, destination + num);

        YES = true;
        for (i = 0; i < num; i++) {
            if ( destination[i] != source[i]) {
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
