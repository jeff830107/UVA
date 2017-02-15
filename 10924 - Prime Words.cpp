#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#define N 1000005

using namespace std;

int prime[N];

void make() {
    int i, j;

    for (i = 0; i < N; i++)
        prime[i] = 1;

    for (i = 2; i < N; i++)
        for (j = 2; i*j < N; j++)
            if (prime[i*j] == 1)
                prime[i*j] = 0;
    return;
}

int main() {

    int i, tmp, sum, len;
    char arr[25];

    make();
    memset(arr, 0, sizeof(arr));

    while ( cin.getline(arr, 25) != NULL ) {
        len = strlen(arr);
        for (sum = 0, i = 0; i < len; i++) {
            if (isupper(arr[i]))
                tmp = arr[i] - 'A' + 27;
            else if (islower(arr[i]))
                tmp = arr[i] - 'a' + 1;

            sum += tmp;
        }
        if (prime[sum] == 1)
            cout << "It is a prime word.\n";
        else
            cout << "It is not a prime word.\n";
        memset(arr, 0, sizeof(arr));
    }

    return 0;
}
