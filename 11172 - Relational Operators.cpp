#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main () {
    long long int T, a, b;

    cin >> T;

    while (T--) {
        cin >> a >> b;
        if (a < b)
            cout << "<\n";
        else if (a > b)
            cout << ">\n";
        else
            cout << "=\n";
    }

    return 0;
}
