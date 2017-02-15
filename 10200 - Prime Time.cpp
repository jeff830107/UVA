#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int table[10001];

int IsPrime(int num) {
    int i;

    if (num % 2 == 0)
        return 0;

    for (i = 3; i*i <= num; i+=2)
        if (num % i == 0)
            return 0;
    return 1;
}

void make() {
    int i, sum;

    for (i = 0; i < 10001; i++) {
        sum =  i * i + i + 41;
        table[i] = IsPrime(sum);
    }
}

int main() {

    int i, sum, a, b;

    make();

    while( scanf("%d %d", &a, &b) != EOF ) {
        if (b < 40)
            printf("100.00\n");
        else {
            sum = 0;
            for (i = a; i <= b; i++) {
                if (table[i])
                    sum++;
            }
            printf("%.2lf\n", (100.0) * sum / (b-a+1) + 1e-8 );  // Unknown reason for adding 1e-8
        }
    }

    return 0;
}
