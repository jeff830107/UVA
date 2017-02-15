#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {

    char time[10];
    int hour, minute;
    double angle, a_hour, a_minute;

    while ( gets(time) ) {
        if (time[0] == '0' && time[2] == '0' && time[3] == '0')  /* 0:00, then END */
            break;
        if (time[1] == ':') {  /* 9:15 */
            hour = time[0] - '0';
            minute = (time[2] - '0') * 10 + time[3] - '0';
        }
        else if (time[2] == ':') {  /* 12:20 */
            hour = (time[0] - '0') * 10 + time[1] - '0';
            minute = (time[3] - '0') * 10 + time[4] - '0';
        }

        /* 12 hours = 360 degrees, so 1 hour = 30 degrees
         * and 60 minutes counts for an hour, which means 30 degrees, so 1 minute = 0.5 degree */
        a_hour = hour * 30.0 + minute * 0.5;

        /* 60 minutes = 360 degrees, so 1 minute = 6 degrees */
        a_minute = minute * 6.0;

        if (a_hour > a_minute)
            angle = a_hour - a_minute;
        else
            angle = a_minute - a_hour;

        // abs return int -> WRONG!!
        // angle = abs(a_hour - a_minute);

        if (angle > 180.0)  /* angle must be smaller than 180 degrees */
            angle = 360.0 - angle;
        printf("%.3lf\n", angle);
    }

    return 0;
}
