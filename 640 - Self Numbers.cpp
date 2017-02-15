#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001

/* EX. b=53812
       53812����a=2 b=5381�A
       5381����a=1 b=538�A
       538����a=8 b=53�A
       53����a=3 b=5 */

bool table[MAX];
/*  ------------------�|Timelimit(�@�ʸU���|�]17�����A�U�����إu�]�@�ʸU��)------------------
void make() {
    int i, num, b, temp;

    for (i = 1; i < MAX; i++)
        table[i] = true;
    for (i = 1; i < MAX; i++) {
        if (table[i]) {
            total = 0;
            temp = i;
            do {
                num = b = i;
                while (b) {
                    num += b % 10;   //a = b % 10
                    b /= 10;
                }

                if (num >= MAX)
                    break;

                table[num] = false;

                i = num;
            } while (1);
            i = temp;
        }
    }
}
*/

void make() {
    int i, num, b;

    for (i = 1; i < MAX; i++)
        table[i] = true;
    for (i = 1; i < MAX; i++) {
        b = num = i;
        while (b) {
            num += b % 10;
            b /= 10;
        }
        if ( num < MAX )
            table[num] = false;
    }
}

/* **************************************************************************************************
    ���覡���W����, �ڭ̥i�H�o�{0~9�|�O�ӭȦA�[�W�ۤv�A���q10�H��O�ӭȥ[�W�U�Ʀr���M�A����6�ӼƦr�Ӭ�
    �H55���ҡA�|�O50�`�M+5�`�M�A��(50+5+0)+(5+5)
    �A�|�@��134 �|�O 100�`�M+30�`�M+4�`�M�A��(100+0+0)+(30+3+0)+(4+4)
    �G�n���W���ƻ�+1
****************************************************************************************************/
/*  -------------------------�ֳ̧t����k--------------------------
void make() {
    for (int i = 1; i < MAX; i++)
        table[i] = true;
    for(int a = 0; a < 10; a++)
        for(int b = 0; b < 10; b++)
            for(int c = 0; c < 10; c++)
                for(int d = 0; d < 10; d++)
                    for(int e = 0; e < 10; e++)
                        for(int f = 0; f < 10; f++)
                            table[a*100001+b*10001+c*1001+d*101+e*11+f+f] = false;
}
*/
/*�ѦҺ��}�Ghttp://hoyusun.blogspot.tw/2012/03/uva-640-self-numbers.html*/

int main()
{
    make();

    for (int i = 1; i < MAX; i++) {
        if (table[i])
            printf("%d\n", i);
    }

    return 0;
}
