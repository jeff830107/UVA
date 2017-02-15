/* ****************************************************************************************
    ���X�X�֪���k���G
        1.��X��Ӷ��X���̤p(�]�i�H�̤j)����(�@�}�l�Ҭ�index)�C  -> while-loop�ӹ�{ (*��)
        2.�����֤̽j�֤p�A�N���j�̪��ȥθ��p�̪��Ȩ��N�A���L�{�|����array�����ȡA
          �Ϥ�����index�ȡC
        3.�̫�u�n��X���X�ӭȤ�����ȡA�N�i�H�o�����X�Ӷ��X�C
**************************************************************************************** */

/* ---------------------------------------------------------------------------------------
    (*��)��while-loop����]�G

        �@�}�l�ɡA�U���X�ҥu���@�Ӥ����A�γ\�i�H��if�ӧP�_�F
        ���O��n�X�h�t�����Y����A�i��|���H�U���p

        EX.
            (4,8) -> (2,4) -> (1,2)  //  (7,9) -> (5,7) -> (3,5)

        ����array�����ȦU�۬�
            table[1] = 1    table[3] = 3
            table[2] = 1    table[5] = 3
            table[4] = 2    table[7] = 5
            table[8] = 4    table[9] = 7

        �Y���ɦ��@�t��(8,9)�A�ڭ̥������o��Ӷ��X�U�۪��̤p��(1�M3)�~��i�涰�X�X�֡A
        �o�Ӯɭԧڭ̴N�ݭn�Τ@��while-loop�A���_�a��array�̪��ȸ�array��index�O�_�۵��A
        ���̬۵��ɡA�N�N���춰�X�����̤p��(�]���D�̤p�Ȫ̡Aarray�̪��ȳ��Q�ﱼ�F)
--------------------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MAX 50001

using namespace std;

int table[MAX];

int main()
{
    int n, m, a, b, ans, cases, a_min, b_min;

    scanf("%d %d", &n, &m);

    cases = 1;
    while ( !(n == 0 && m == 0) ) {
        if (n == 0)
            break;

        /* �@�}�larray�����ȸ�index�ۦP�A�p�G���S�t���T�A�h�|��n�Ӥ��P��index�A�]�N�On�Ӷ��X */
        for (int i = 1; i <= MAX; i++)
            table[i] = i;

        /* Ū���U�Ӫ�M���t���T */
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &a, &b);

            while ( b != table[b])  /* ��Ӷ��X���̤p�� */
                b = table[b];
            while ( a != table[a])  /* ��Ӷ��X���̤p�� */
                a = table[a];

            if (a < b)        /* a���p�A�Nb��a���N(b�Q�X�֨�a) */
                table[b] = a;
            else if (a > b)   /* b���p�A�Na��b���N(a�Q�X�֨�b) */
                table[a] = b;

            /* �Y��̬۵��A�N���̦��N�w�b�P�@�Ӷ��X���A���ݥ���ʧ@ */
        }

        ans = 0;
        for (int i = 1; i <= n; i++)
            /* array�����ȸ�index�ȬۦP�A�N���Ƭ��Ӷ��X�̤p���ȡA���ƬO���X���Y�A���X��+1 */
            if (i == table[i])
                ans++;

        printf("Case %d: %d\n", cases, ans);

        scanf("%d %d", &n, &m);
        cases++;
    }

    return 0;
}
