#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#define N 1000005

using namespace std;

int prime[N], table[N], accumulation[N];;

void make() {
    int i, j;

    for (i = 0; i < N; i++)
        prime[i] = 1;

    prime[0] = prime[1] = 0;
    for (i = 2; i < N; i++)
        for (j = 2; i*j < N; j++)
            if (prime[i*j] == 1)
                prime[i*j] = 0;
    return;
}

int SUM(int num) {
    int sum;

    sum = 0;
    while (num >= 10) {
        sum += num % 10;
        num /= 10;
    }
    sum += num;

    return sum;
}

void DIGIT() {
    int i, digit;

    accumulation[0] = 0;
    for (i = 1; i <= N; i++) {
        digit = SUM(i);
        if (prime[i] && prime[digit])
            accumulation[i] = accumulation[i-1] + 1;
        else
            accumulation[i] = accumulation[i-1];
    }
}

int main() {

    int T, a, b;

    make();
    DIGIT();

    cin >> T;
    while (T--) {
        cin >> a >> b;
        cout << accumulation[b] - accumulation[a-1] << endl;
    }

    return 0;
}
