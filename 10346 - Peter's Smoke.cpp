#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    int sum, emp, tmp, i;
    while (cin >> emp >> i) {
        sum = emp;
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
