#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {

    char in;
    int alphabet[52];
    char ch[52];
    int index, i, Max;

    for (i = 0; i < 52; i++) {
        if (i < 26)
            ch[i] = (char)('A' + i);
        else
            ch[i] = (char)('a' + i - 26);
    }

    while ( scanf("%c", &in) != EOF ) {
        // Initialization
        for (i = 0; i < 52; i++)
            alphabet[i] = 0;

        // Processing the first character (which means this line is not EOF)
        if (in >= 'A' && in <= 'Z') {
            index = in - 'A';
            alphabet[index]++;
        }
        else if (in >= 'a' && in <= 'z') {
            index = (in - 'a') + 26;
            alphabet[index]++;
        }

        // Processing the remaining character
        while (1) {
            scanf("%c", &in);
            if (in == '\n')
                break;
            if (in >= 'A' && in <= 'Z') {
                index = in - 'A';
                alphabet[index]++;
            }
            else if (in >= 'a' && in <= 'z') {
                index = (in - 'a') + 26;
                alphabet[index]++;
            }
        }

        // Finding the highest frequency character
        Max = 0;
        for (i = 0; i < 52; i++) {
            if (alphabet[i] > Max)
                Max = alphabet[i];
        }
        for (i = 0; i < 52; i++)
            if (alphabet[i] == Max)
                printf("%c", ch[i]);
        printf(" %d\n", Max);
    }

    return 0;
}
