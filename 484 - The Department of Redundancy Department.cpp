#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#define N 100005

using namespace std;

int main() {

    int arr[N], numbers[N];
    int num, i, cnt;

    for (i = 0; i < N; i++)
        numbers[i] = 0;
    i = 0;   cnt = 0;
    while ( scanf("%d", &num) != EOF ) {
        numbers[num]++;
        arr[i++] = num;
        cnt++;
    }
    for (i = 0; i < cnt; i++) {
        if (numbers[ arr[i] ] != 0) {
            cout << arr[i] << " " << numbers[ arr[i] ] << endl;
            numbers[ arr[i] ] = 0;
        }
    }

    return 0;
}
