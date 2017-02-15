#include <stdlib.h>
#include <stdio.h>

int main()
{
    int times, comma, temp, base, temp1, base1;
    double value, sum;

    scanf("%d", &times);

    for (int i = 1; i <= times; i++) {
        sum = 0;
        comma = 0;
        for (int j = 1; j <= 12; j++) {
            scanf("%lf", &value);
            sum += value;
        }
        sum /= 12.0;

        temp = temp1 = (int)sum;
        base = 1;
        while ( (temp / 1000) > 0) {
            comma++;
            temp /= 1000;
            base *= 1000;
        }

        base1 = base;
        for (int j = 1; j <= comma; j++) {
            temp = (int)sum;
            sum = sum - (temp / base) * base;
            base /= 1000;
        }

        printf("%d $", i);
        for (int j = 1; j <= comma; j++) {
            printf("%d", temp1 / base1);
            if (j == comma)
                printf(",");
            temp1 = temp1 % base1;
            base1 /= 1000;
        }
        printf("%.2lf\n", sum);
    }

    return 0;
}
