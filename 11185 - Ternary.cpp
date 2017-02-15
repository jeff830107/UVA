#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int arr[10000];

void Ternary( int num ) {
    int i, j;

    for (i = 0; num >= 3; i++) {
        arr[i] = num % 3;
        num /= 3;
    }
    arr[i] = num;

    for (j = i; j >= 0; j--)
        cout << arr[j];
    cout << endl;
}

int main () {
    int num, ans;

    cin >> num;
    while (num >= 0) {
        memset(arr, 0, sizeof(arr));
        Ternary(num);

        cin >> num;
    }

    return 0;
}
