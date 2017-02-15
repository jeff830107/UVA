#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAX 1005

using namespace std;

int main() {
    int i, len, a, b, dif;
    char arr[1005];

    /* Critical Input: 00011 */
    while ( cin.getline(arr, MAX), !(arr[0] == '0' && arr[1] == '\0') ) {
        len = strlen(arr);
        for (i = 0, a = 0, b = 0; i < len; i++) {
            if (i % 2 == 0)
                a += arr[i] - '0';
            else
                b += arr[i] - '0';
        }
        dif = (a > b) ? (a - b) : (b - a);

        for (i = 0; i < len; i++)
            cout << arr[i];
        if (dif % 11 == 0)
            cout << " is a multiple of 11.\n";
        else
            cout << " is not a multiple of 11.\n";
    }

    return 0;
}
