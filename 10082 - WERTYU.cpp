#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

char table[100];

void make() {
    /*table['A'] = */
    table['B'] = 'V';
    table['C'] = 'X';
    table['D'] = 'S';
    table['E'] = 'W';
    table['F'] = 'D';
    table['G'] = 'F';
    table['H'] = 'G';
    table['I'] = 'U';
    table['J'] = 'H';
    table['K'] = 'J';
    table['L'] = 'K';
    table['M'] = 'N';
    table['N'] = 'B';
    table['O'] = 'I';
    table['P'] = 'O';
    /*table['Q'] = */
    table['R'] = 'E';
    table['S'] = 'A';
    table['T'] = 'R';
    table['U'] = 'Y';
    table['V'] = 'C';
    table['W'] = 'Q';
    table['X'] = 'Z';
    table['Y'] = 'T';
    /*table['Z'] = */
    table['.'] = ',';
    table['/'] = '.';
    table['['] = 'P';
    table[']'] = '[';
    table[';'] = 'L';
    table[','] = 'M';
    table['1'] = '`';
    table['2'] = '1';
    table['3'] = '2';
    table['4'] = '3';
    table['5'] = '4';
    table['6'] = '5';
    table['7'] = '6';
    table['8'] = '7';
    table['9'] = '8';
    table['0'] = '9';
    table['-'] = '0';
    table['='] = '-';
    table['\''] = ';';  /* ¦r¤¸' */
    table['\\'] = ']';  /* ¦r¤¸\ */
}

int main()
{
    make();
    char ch;

    while ( (ch = getchar()) != EOF ) {
        if (ch != ' ' && ch != '\n')
            printf("%c", table[ch]);
        else
            printf("%c", ch);
    }


    return 0;
}
