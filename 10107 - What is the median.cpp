#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
#include <algorithm>

using namespace std;

int main()
{
    int x, num = 0, mid, arr[MAX], last = 0;

    while (scanf("%d", &x) != EOF) {
        arr[last++] = x;
        sort(arr, arr+last);
        num++;
        if (num % 2 == 0)
            mid = ( arr[num / 2] + arr[num / 2 - 1] ) / 2;
        else
            mid = arr[num / 2];
        printf("%d\n", mid);
    }

    return 0;
}
