#include <stdio.h>
#include <stdlib.h>

char id[50];

int main()
{
    int last_increase_front, end, last_big;
    char temp, c;

    c = getchar();
    while (c != '#') {

        last_increase_front = last_big = -1;

        for (int i = 0; i < 50; i++)
            id[i] = '0';

        for (int i = 0; c != '\n'; i++) {
            id[i] = c;
            c = getchar();
            end = i;
        }

        /* ��̫�@�ӥ��� */
        for (int i = 0; i <= end - 1; i++) {
            if (id[i] < id[i + 1] && id[i + 1] <= 'z' && id[i] >= 'a') {
                last_increase_front = i;
            }
        }

        if (last_increase_front == -1) {
            printf("No Successor");
        }
        else {
            /* ��̫�@�Ӥ� "���ǫe�Y����" �٤j���� */
            for (int i = last_increase_front + 1; i <= end; i++) {
                if (id[i] > id[last_increase_front]) {
                    last_big = i;
                }
            }

            /* ��̥洫 */
            temp = id[last_increase_front];
            id[last_increase_front] = id[last_big];
            id[last_big] = temp;

            for (int i = 0; i <= last_increase_front; i++)
                printf("%c", id[i]);

            for (int i = end; i > last_increase_front; i--)
                printf("%c", id[i]);
        }

        printf("\n");

        c = getchar();

    }

    return 0;
}
