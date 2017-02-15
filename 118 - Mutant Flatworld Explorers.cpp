#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int x_d[4] = { 0, 1, 0,-1};  // N, E, S, W
int y_d[4] = { 1, 0,-1, 0};  // N, E, S, W

int main() {
	int X, Y;
	int x, y;
	int cnd;  // condition
	char initial, buffer;
	char cmd[100], Map[51][51];
	int flag, len;

    memset(Map, 0, sizeof(Map));

	scanf("%d%d", &X, &Y);
	while (scanf("%d%d%c%c%c", &x, &y, &buffer, &initial, &buffer) != EOF) {
		switch(initial) {
			case 'N': cnd = 0; break;
			case 'E': cnd = 1; break;
			case 'S': cnd = 2; break;
			case 'W': cnd = 3; break;
		}

		gets(cmd);

		flag = 0;
		len = strlen(cmd);
		for (int i = 0; i < len; i++) {
			if (cmd[i] == 'R') {
				if ((cnd + 1) == 4)
					cnd = 0;
				else
					cnd += 1;
			}
			else if (cmd[i] == 'L') {
				if ((cnd - 1) == -1)
					cnd = 3;
				else
					cnd -= 1;
			}
			else if (cmd[i] == 'F') {
				if (x + x_d[cnd] > X || x + x_d[cnd] < 0 || y + y_d[cnd] > Y || y + y_d[cnd] < 0) {
					if (Map[x][y] == 0) {
                        Map[x][y] = 1;
                        flag = 1;
                        break;
					}
				}
				else {
                    x += x_d[cnd];
                    y += y_d[cnd];
				}
			}
		}

		switch(cnd) {
			case 0: initial = 'N'; break;
			case 1: initial = 'E'; break;
			case 2: initial = 'S'; break;
			case 3: initial = 'W'; break;
		}

		printf("%d %d %c", x, y, initial);
		if (flag)
			printf(" LOST\n");
		else
			printf("\n");
	}

	return 0;
}
