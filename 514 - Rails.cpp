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

            for (i = 1; i <= 1000; i++)  /* ���[�ҦbA�a */
                car[i] = 0;

            for (i = 1; i <= number; i++) {  /* Ū�C�@����� */

                scanf("%d", &station);

                if (valid == true) {

                    if (station == 0) {
                        stop = 1;
                        break;
                    }

                    if (station <= number) {
                        for (j = station + 1; j <= number; j++) {  /* �ˬd���S����o�Ө��[�٤j�����[�b���� */
                            if (car[j] == 1)
                                valid = false;
                        }

                        if (valid == true) {  /* �S����o�Ө��[�٤j�����[�b�����A�~���ˬd */
                            for (j = station - 1; j >= 1; j--) {  /* �ˬd���S����o�Ө��[�٤p�����[�ٯd�bA�a */
                                if (car[j] == 0)
                                    car[j] = 1;  /* �����ܡA�⨺�Ǩ��[���쨮�� */
                            }
                        }

                        if (valid == true)  /* �q�L�ˬd�A�����[�e��B�a�A���~��U�@�Ө��[�άO�i��U�@������ */
                            car[station] = 2;
                    }
                    else
                        valid = false;
                }
            }

            if (stop == 1)  /* �o�Ӽƥؤw�g���է����A���}while-loop */
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
