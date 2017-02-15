#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main () {
    int T, a, b, i, j, sum, x;

    cin >> T;

    for (x = 1; x <= T; x++) {
        cin >> a >> b;
        if (a % 2 == 0) {
            i = a+1;
            if (b % 2 == 0)
                j = b-1;
            else
                j = b;
        }
        else {
            i = a;
            if (b % 2 == 0)
                j = b-1;
            else
                j = b;
        }
        for (sum = 0; i <= j; i+=2)
            sum += i;
        cout << "Case " << x << ": " << sum << endl;

    }

    return 0;
}
