#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int GCD(int a, int b) {
    int c;
    while ( a != 0 ) {
        c = a;
        a = b % a;
        b = c;
    }
    return b;
}

int main () {
    int N, G, i, j;

    cin >> N;
    while (N != 0) {
        G = 0;
        for (i = 1; i < N; i++)
            for (j = i+1; j <= N; j++)
                G += GCD(i, j);
        cout << G << endl;

        cin >> N;
    }

    return 0;
}
