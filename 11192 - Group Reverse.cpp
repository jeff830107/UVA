//#define TEST

#ifndef TEST

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {

    int n, i, j, k, len, LEN;
    char str[105];

    while (scanf("%d",&n)!=EOF&&n) {

        cin >> str;
        LEN = strlen(str);
        len = LEN / n;
        for (i = len-1; i <= LEN; i+=len) {
            if (LEN % n != 0)
                if (i > LEN-len)
                    break;
            for (j = i, k = 0; k < len; j--, k++)
                cout << str[j];
        }
        cout << endl;
    }

    return 0;
}

#else
#include<stdio.h>
#include<string.h>
int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        char s[110];
        scanf("%s",s);
        int len=strlen(s);
        int k=len/n;
        int i,j;
        for(i=0;i<n;i++){
            int z=0;
            for(j=k-1+k*i;z<k;z++,j--)printf("%c",s[j]);
            }
        printf("\n");
        }
    return 0;
    }
#endif
