#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {

    int N, i, cost, sum;
    int arr[5005];

    cin >> N;
    while (N != 0) {
        memset(arr, 0, sizeof(arr));
        for (i = 0; i < N; i++)
            cin >> arr[i];

        sort(arr, arr + N);

        for (sum = 0, cost = 0, i = 0; i < N-1; i++) {
            cost = arr[i] + arr[i+1];
            sum += cost;
            arr[i] = 0;
            arr[i+1] = cost;
            sort(arr+i+1, arr + N);
        }
        cout << sum << endl;

        cin >> N;
    }

    return 0;
}
