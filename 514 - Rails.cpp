#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, i, j, car[1001], stop, station;
    bool valid;

    scanf("%d", &number);

    while (number != 0) {

        stop = 0;

        while (1) {

            valid = true;

            for (i = 1; i <= 1000; i++)  /* 車廂皆在A地 */
                car[i] = 0;

            for (i = 1; i <= number; i++) {  /* 讀每一行測資 */

                scanf("%d", &station);

                if (valid == true) {

                    if (station == 0) {
                        stop = 1;
                        break;
                    }

                    if (station <= number) {
                        for (j = station + 1; j <= number; j++) {  /* 檢查有沒有比這個車廂還大的車廂在車站 */
                            if (car[j] == 1)
                                valid = false;
                        }

                        if (valid == true) {  /* 沒有比這個車廂還大的車廂在車站，繼續檢查 */
                            for (j = station - 1; j >= 1; j--) {  /* 檢查有沒有比這個車廂還小的車廂還留在A地 */
                                if (car[j] == 0)
                                    car[j] = 1;  /* 有的話，把那些車廂移到車站 */
                            }
                        }

                        if (valid == true)  /* 通過檢查，讓車廂前往B地，並繼續下一個車廂或是進行下一輪測試 */
                            car[station] = 2;
                    }
                    else
                        valid = false;
                }
            }

            if (stop == 1)  /* 這個數目已經測試完畢，離開while-loop */
                break;

            if (valid == true)
                printf("Yes\n");
            else
                printf("No\n");
        }

        printf("\n");
        scanf("%d", &number);
    }


    return 0;
}
