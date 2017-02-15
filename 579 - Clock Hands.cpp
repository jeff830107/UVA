#include <stdlib.h>
#include <stdio.h>

int main() {

    int H, M;
    double angle_H, angle_M, angle;
    char time[10];

    gets(time);
    while (!(time[0] == '0' && time[2] == '0' && time[3] == '0')) {
        if (time[1] == ':') {  // 9:00
            H = time[0] - '0';
            M = (time[2] - '0') * 10 + time[3] - '0';
        }
        else {  // 11:00
            H = (time[0] - '0') * 10 + time[1] - '0';
            M = (time[3] - '0') * 10 + time[4] - '0';
        }

        angle_H = H * 30.0 + M * 0.5;
        angle_M = M * 6.0;

        if (angle_H >= angle_M)
            angle = angle_H - angle_M;
        else
            angle = angle_M - angle_H;

        if (angle <= 180.0)
            printf("%.3lf\n", angle);
        else
            printf("%.3lf\n", 360.0 - angle);

        gets(time);
    }

    return 0;
}
