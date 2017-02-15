// Math Problem
// using Heron's extend formula (calculate area with medians)

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {

    double a, b, c, s, ans;

    while (cin >> a >> b >> c) {
        if (a+b <= c || a+c <= b || b+c <= a)  // [important] it's <=, not <.
            cout << "-1.000\n";
        else {
            s = (a+b+c)/2;
            ans = sqrt( s*(s-a)*(s-b)*(s-c) ) * (4.0/3.0);  // Heron's formula (extended)
            printf("%.3lf\n", ans);
        }
    }

    return 0;
}
