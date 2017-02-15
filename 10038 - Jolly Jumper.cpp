#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

int main () {

    int N, i, dif;
    int arr[3005], happen[3005];
    char buffer;
    bool jolly;

    while ( scanf("%d", &N) != EOF ) {
        memset(happen, 0, sizeof(happen));

        for (i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        scanf("%c", &buffer);

        for (jolly = true, i = 0; i < N-1; i++) {
            dif = abs( arr[i] - arr[i+1] );
            if (dif >= N || happen[dif] == 1) {
                jolly = false;
                break;
            }
            happen[dif]++;
        }
        if (jolly)
            cout << "Jolly\n";
        else
            cout << "Not jolly\n";
    }

    return 0;
}
