#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int sum, emp, tmp, i, extra, T;

    cin >> T;

    while (T--) {
        cin >> emp >> extra >> i;
        sum = 0;
        emp += extra;
        while (emp >= i) {
            sum += emp / i;
            tmp = emp % i;
            emp /= i;
            emp += tmp;
        }
        cout << sum << endl;
    }

    return 0;
}
