#include <stdlib.h>
#include <stdio.h>

int summing_digits(int x) {
    int result = 0;

    while (x >= 10) {
        result += x % 10;
        x /= 10;
    }
    result += x;

    if (result >= 10)
        result = summing_digits(result);

    return result;
}

int main()
{
    int num;

    scanf("%d", &num);
    while (num != 0) {
        if (num >= 10)
            num = summing_digits(num);

        printf("%d\n", num);
        scanf("%d", &num);
    }

    return 0;
}
