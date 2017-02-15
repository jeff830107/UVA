#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

char put[][5] = { "``", "''"};

int main()
{
    int k = 0;
    char c;
    while ( ( c = getchar() ) != EOF ) {

        if (c == '"') {
            printf("%s", put[k]);
            k = !k;
        }
        else
            putchar(c);
    }


    return 0;
}
