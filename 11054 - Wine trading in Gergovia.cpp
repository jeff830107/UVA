#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main() {

    long long int num, i, j, sum;
    long long int arr[100005];

    cin >> num;

    while (num != 0) {
        for (i = 0; i < num; i++)
            cin >> arr[i];

        sum = 0;
        for (i = 0; i < num; i++) {
            if (arr[i] > 0) {
                j = i + 1;
                while (arr[i] > 0) {
                    if (arr[j] < 0) {
                        if ( arr[i] > abs(arr[j]) ) {  // 4, -3 -> 1, 0
                            arr[i] += arr[j];
                            sum += (j-i) * (abs(arr[j]));
                            arr[j] = 0;
                        }
                        else {  // 3, -4 -> 0, -1
                            arr[j] += arr[i];
                            sum += (j-i) * (arr[i]);
                            arr[i] = 0;
                        }

                    }
                    j++;
                }
            }
            else {
                j = i + 1;
                while (arr[i] < 0) {
                    if (arr[j] > 0) {
                        if ( arr[j] > abs(arr[i]) ) {  // -3, 4 -> 0, 1
                            arr[j] += arr[i];
                            sum += (j-i) * (abs(arr[i]));
                            arr[i] = 0;
                        }
                        else {  // -4, 3 -> -1, 0
                            arr[i] += arr[j];
                            sum += (j-i) * (arr[j]);
                            arr[j] = 0;
                        }
                    }
                    j++;
                }
            }
        }
        cout << sum << endl;

        cin >> num;
    }

    return 0;
}
