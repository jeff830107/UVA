#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main() {
    int cases, N, i, cnt;
    int dic_len[1000];
    char dic[1000][1000], dic_cpy[1000][1000];
    char cmd[21], cmd_cpy[21];
    char buffer;

    scanf("%d", &cases);
    while (cases--) {
        scanf("%c", &buffer);
        scanf("%d", &N);
        scanf("%c", &buffer);

        memset(dic, 0, sizeof(dic));
        for (i = 0; i < N; i++) {
            gets(dic[i]);
            strcpy(dic_cpy[i], dic[i]);
            dic_len[i] = strlen(dic[i]);
        }
        for (i = 0; i < N; i++)
            sort(dic[i], dic[i] + dic_len[i]);

        while ( gets(cmd) && !(cmd[0] == 'E' && cmd[1] == 'N' && cmd[2] == 'D') ) {
            printf("Anagrams for: %s\n", cmd);
            strcpy(cmd_cpy, cmd);
            sort(cmd, cmd + strlen(cmd));
            for (cnt = 1, i = 0; i < N; i++) {
                if(strcmp(cmd, dic[i]) == 0)
                    printf("  %d) %s\n", cnt++, dic_cpy[i]);
            }
            if (cnt == 1)
                printf("No anagrams for: %s\n", cmd_cpy);
            memset(cmd, 0, sizeof(cmd));
        }
        if (cases != 0)
            printf("\n");
    }

    return 0;
}
