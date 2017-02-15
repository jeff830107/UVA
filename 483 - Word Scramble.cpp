#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#define N 10005

using namespace std;

int main () {
    char arr[N];
    int i, j, len, last;

    memset(arr, 0, sizeof(arr));
    while (cin.getline(arr, N) != NULL) {
        len = strlen(arr);
        last = i = 0;
        while (i <= len-1) {
            while (arr[i] != ' ' && i != len-1)
                i++;
            if (i != len-1) {
                for (j = i-1; j >= last; j--)
                    cout << arr[j];
                cout << " ";
            }
            else {
                for (j = i; j >= last; j--)
                    cout << arr[j];
            }
            last = ++i;
        }
        cout << endl;

        memset(arr, 0, sizeof(arr));
    }

    return 0;
}
