#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// UVA
int main() {

    int sum, emp, tmp;
    while (cin >> emp) {
        sum = emp;
        while (emp >= 3) {
            sum += emp / 3;
            tmp = emp % 3;
            emp /= 3;
            emp += tmp;
        }
        if (emp == 2)
            sum++;
        cout << sum << endl;
    }

    return 0;
}

/*
// MIS Online Judge
int main() {

    int T, sum, emp, tmp;

    cin >> T;

    while (T--) {
        cin >> emp;
        sum = emp;
        while (emp >= 3) {
            sum += emp / 3;
            tmp = emp % 3;
            emp /= 3;
            emp += tmp;
        }
        if (emp == 2)
            sum++;
        cout << sum << endl;
    }

    return 0;
}
*/
