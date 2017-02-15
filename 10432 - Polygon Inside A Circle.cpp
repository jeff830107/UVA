#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI acos(-1)

int main()
{
    double area, r, n;

    while ( scanf("%lf %lf", &r, &n) != EOF ) {
        area = n * r * r * sin( (2.0 * PI) / n ) / 2.0;
        printf("%.3lf\n", area);
    }

    return 0;
}
