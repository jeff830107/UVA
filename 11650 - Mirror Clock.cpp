#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int num, hour, minute, m_hour, m_minute;
    char time[10];
    char buffer;
    bool AM, noon;

    scanf("%d", &num);
    scanf("%c", &buffer);
    while (num--) {
        gets(time);
        hour = (time[0] - '0') * 10 + time[1] - '0';
        minute = (time[3] - '0') * 10 + time[4] - '0';

        /*                  *
         * < Time Format >  *
         *  01:00 to 12:59  *
         *                  */

        noon = false;
        /* Check AM, PM, or noon */
        if (hour == 12 && minute == 0)
            noon = true;
        if (!noon && hour >= 12)
            AM = false;
        else
            AM = true;

        if (noon)  /* noon */
            printf("12:00\n");
        else {
            if (AM) {  /* AM */
                /* MIRROR */
                m_minute = 60 - minute;
                if (minute == 0)
                    m_hour = 12 - hour;
                else
                    m_hour = 11 - hour;

                /* ERROR CORRECTION */
                if (m_minute == 60)  /* EX: 05:00 -> 07:00 */
                    m_minute = 0;
                if (m_hour == 0)  /* EX: 11:47 -> 12:13*/
                    m_hour = 12;
            }
            else {  /* PM */
                m_hour = 11;  /* reflects to 11, EX: 12:43 -> 11:17 */
                m_minute = 60 - minute;
            }

            /* Output Hour */
            if (m_hour == 0)
                ;
            else if (m_hour < 10)
                printf("0%d:", m_hour);
            else
                printf("%d:", m_hour);

            /* Output Minute */
            if (m_minute < 10)
                printf("0%d\n", m_minute);
            else
                printf("%d\n", m_minute);
        }
    }

    return 0;
}
