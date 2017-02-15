#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int f(int N) {
    if (N >= 101)
        return (N-10);
    return f(f(N+11));
}

int main () {
    int N, ans;

    cin >> N;
    while (N != 0) {
        ans = f(N);
        cout << "f91(" << N << ") = " << ans << endl;
        cin >> N;
    }

    return 0;
}
