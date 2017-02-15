#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#define MAX 10000

using namespace std;

int main() {

	int N, i, j, num, cnt, flag, Case, flag1;
	int arr[100];
	int answer[MAX];

	Case = 1;
	while (scanf("%d", &N) != EOF) {

		printf("Case #%d: ", Case++);
		memset(arr, 0, sizeof(arr));
		memset(answer, 0, sizeof(answer));

		flag1 = 1;
		for (i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] <= arr[i-1])
				flag1 = 0;
		}
		if (flag1 == 0)
			printf("It is not a B2-Sequence.\n\n");
		else {
			cnt = 0;
			for (i = 1; i <= N; i++) {
				for (j = i; j <= N; j++) {
					num = arr[i] + arr[j];
					answer[cnt++] = num;
				}
			}

			sort(answer, answer + cnt);

			flag = 1;
			for (i = 0; i < cnt; i++) {
				if (answer[i] == answer[i+1]) {
					flag = 0;
					break;
				}
			}

			if (flag)
				printf("It is a B2-Sequence.\n\n");
			else
				printf("It is not a B2-Sequence.\n\n");

		}

	}

	return 0;
}
