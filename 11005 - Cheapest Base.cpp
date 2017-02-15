#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

long long int table[40], arr[40];

void Cheap(long long int num) {
    int tmp, i, sum, mod;

    for (i = 2; i <= 36; i++) {
        tmp = num;
        sum = 0;
        while (tmp >= i) {
            mod = tmp % i;
            sum += arr[mod];
            tmp /= i;
        }
        sum += arr[tmp];
        table[i] = sum;
    }
}

int main() {

    long long int T, i, j, k, num, N, mini;

    cin >> T;

    for (i = 1; i <= T; i++) {
        cout << "Case " << i << ":" << endl;
        for (j = 0; j < 36; j++)
            cin >> arr[j];

        cin >> N;
        for (j = 0; j < N; j++) {
            cin >> num;
            cout << "Cheapest base(s) for number " << num << ":";

            Cheap(num);

            mini = table[2];
            for (k = 3; k <= 36; k++)
                if (table[k] < mini)
                    mini = table[k];

            for (k = 2; k <= 36; k++)
                if (table[k] == mini)
                    cout << " " << k;
            cout << endl;
        }

        if (i != T)
            cout << endl;
    }

    return 0;
}
