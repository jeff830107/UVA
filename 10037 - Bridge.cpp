#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define MAX 1000

using namespace std;

int main()
{
    int n, A, B, a, b, time[MAX], people, ans, GOD;
    char buffer;

    scanf("%d", &GOD);

    for (int m = 1; m <= GOD; m++) {

        if (m != 1)                  /* the output has to be seperated by the blank line between several datas */
            printf("\n");

        scanf("%c", &buffer);        /* the blank line */

    	for (int i = 0; i < MAX; i++)
        	time[i] = 0;

    	scanf("%d", &n);

    	/* Ū�J�ƾ� */
    	for (int i = 0; i < n; i++) {
        	scanf("%d", &time[i]);
    	}

    	/* �Ѥp�ƨ�j */
    	sort(time, time + n);

    	if (n == 1)                /* �u���@�ӤH�����p */
        	printf("%d\n%d\n", time[0], time[0]);

    	else {

        	people = n;
        	ans = 0;

        	/* ���`�ɶ� */

        	while (people > 3) {     /* �C���]��while-loop�A����ӤH�L���A��L�����H�٦b�쩤 */
            	/* Case1 > Case2 */
            	if (time[0] * 2 + time[people-1] + time[people-2] > time[1] * 2 + time[0] + time[people-1]) {
                	ans += time[1] * 2 + time[0] + time[people-1];
            	}
            	/* Case1 < Case2 */
            	else {
                	ans += time[0] * 2 + time[people-1] + time[people-2];
            	}

            	people -= 2;
        	}
        	if (people == 3) {  /* �ѤU�e�T�� */
            	ans += time[0]+ time[1]+ time[2];
        	}
        	else if (people == 2) {  /* �ѤU�e��֪� */
            	ans += time[1];
        	}

        	/* �⧹�`�ɶ�~  �L�X�ӧa�I */
        	printf("%d\n", ans);


        	/* �L�X�L�{ */
        	people = n;
        	while (people > 3) {     /* �C���]��while-loop�A����ӤH�L���A��L�����H�٦b�쩤 */
            	/* Case1 > Case2 */
            	if (time[0] * 2 + time[people-1] + time[people-2] > time[1] * 2 + time[0] + time[people-1]) {
                	printf("%d %d\n", time[0], time[1]);
                	printf("%d\n", time[0]);
                	printf("%d %d\n", time[people-2], time[people-1]);
                	printf("%d\n", time[1]);
            	}
            	/* Case1 < Case2 */
            	else {
                	printf("%d %d\n", time[0], time[people-1]);
                	printf("%d\n", time[0]);
                	printf("%d %d\n", time[0], time[people-2]);
                	printf("%d\n", time[0]);
            	}

            	people -= 2;
        	}
        	if (people == 3) {
            	printf("%d %d\n", time[0], time[2]);
            	printf("%d\n", time[0]);
            	printf("%d %d\n", time[0], time[1]);
        	}
        	else if (people == 2) {
            	printf("%d %d\n", time[0], time[1]);
        	}
		}
	}

    return 0;
}
