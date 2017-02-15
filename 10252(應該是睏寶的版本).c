#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1010

int main(){

    char i,j,s1[SIZE],s2[SIZE];

    while(gets(s1)){
        gets(s2);
        int a1[26] = {},a2[26] = {};
        for(i = 0;i < strlen(s1);i++){
            if((s1[i] >= 'a') && (s1[i] <= 'z'))
                a1[s1[i]-'a']++;
        }
        for(i = 0;i < strlen(s2);i++){
            if((s2[i] >= 'a') && (s2[i] <= 'z'))
                a2[s2[i]-'a']++;
        }
        for(i = 0;i < 26;i++){
            for(j = 0;j < a1[i] && j < a2[i];j++)
                printf("%c",'a'+i);
        }
        printf("\n");
    }

    return 0;
}
