#include <stdlib.h>
#include <stdio.h>
#include <iostream>
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

int REV(int num) {
    int sum;

    sum = 0;
    while (num >= 10) {
        sum = sum * 10 + (num % 10);
        num /= 10;
    }
    sum = sum * 10 + num;

    return sum;
}

int main() {

    int num, rev;

    make();

    while (cin >> num != NULL) {
        rev = REV(num);
        if (prime[num]) {
            if (prime[rev] && rev != num)
                cout << num << " is emirp.\n";
            else
                cout << num << " is prime.\n";
        }
        else
            cout << num << " is not prime.\n";
    }

    return 0;
}
