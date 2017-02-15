#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    humidex = temperature + h
    h = (0.5555)*(e - 10.0)
    e = 6.11 * exp [5417.7530 * ((1/273.16) - (1/(dewpoint+273.16)))]
*/

int main()
{
    char ch1, ch2;
    double num1, num2, T, D, H;

    scanf("%c", &ch1);
    while (ch1 != 'E') {
        scanf("%lf %c%lf", &num1, &ch2, &num2);

        if (ch1 == 'T' && ch2 == 'D') {
            T = num1;
            D = num2;
            H = T + ( 0.5555 * (  ( 6.11 * exp( 5417.7530 * ((1/273.16) - (1/(D+273.16))) ) )  - 10.0 )  );
        }
        else if (ch1 == 'D' && ch2 == 'T') {
            T = num2;
            D = num1;
            H = T + ( 0.5555 * (  ( 6.11 * exp( 5417.7530 * ((1/273.16) - (1/(D+273.16))) ) )  - 10.0 )  );
        }
        else if (ch1 == 'T' && ch2 == 'H') {
            T = num1;
            H = num2;
            D = pow(  (  (1/273.16) - (  log(  ( (H-T) / (0.5555) + 10.0 ) / 6.11 ) / 5417.7530  )  )   ,-1) - 273.16;
        }
        else if (ch1 == 'H' && ch2 == 'T') {
            T = num2;
            H = num1;
            D = pow(  (  (1/273.16) - (  log(  ( (H-T) / (0.5555) + 10.0 ) / 6.11 ) / 5417.7530  )  )   ,-1) - 273.16;
        }
        else if (ch1 == 'D' && ch2 == 'H') {
            D = num1;
            H = num2;
            T = H - ( 0.5555 * (  ( 6.11 * exp( 5417.7530 * ((1/273.16) - (1/(D+273.16))) ) )  - 10.0 )  );
        }
        else if (ch1 == 'H' && ch2 == 'D') {
            D = num2;
            H = num1;
            T = H - ( 0.5555 * (  ( 6.11 * exp( 5417.7530 * ( (1/273.16) - (1/(D+273.16)) ) ) )  - 10.0 )  );
        }

        printf("T %.1lf D %.1lf H %.1lf\n", T, D, H);



        scanf(" %c", &ch1);
    }

    return 0;
}
