#include <stdio.h>
#include <stdlib.h>
#define MAX 1000001

/* EX. b=53812
       53812分成a=2 b=5381，
       5381分成a=1 b=538，
       538分成a=8 b=53，
       53分成a=3 b=5 */

bool table[MAX];
/*  ------------------會Timelimit(一百萬筆會跑17億次，下面那種只跑一百萬次)------------------
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
    此方式較上面快, 我們可以發現0~9會是該值再加上自己，但從10以後是該值加上各數字的和，切成6個數字來看
    以55為例，會是50總和+5總和，為(50+5+0)+(5+5)
    再舉一例134 會是 100總和+30總和+4總和，為(100+0+0)+(30+3+0)+(4+4)
    故要乘上倍數需+1
****************************************************************************************************/
/*  -------------------------最快速的方法--------------------------
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
/*參考網址：http://hoyusun.blogspot.tw/2012/03/uva-640-self-numbers.html*/

int main()
{
    make();

    for (int i = 1; i < MAX; i++) {
        if (table[i])
            printf("%d\n", i);
    }

    return 0;
}
