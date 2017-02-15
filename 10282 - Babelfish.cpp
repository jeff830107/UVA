#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>

using namespace std;

int main()
{
    char input[100000];
    char *s1, *s2;
    string english, foreign;

    map<string, string> dictionary;

    /* «Ø¦r¨å */
    while (gets(input)) {
        if (input[0] == '\0')
            break;

        s1 = strtok(input, " ");
        s2 = strtok(NULL, " ");

        english = s1;
        foreign = s2;

        dictionary.insert( pair<string, string> (foreign, english) );
    }

    map<string, string>::iterator it;
    string word;



    while (cin >> word) {

        it = dictionary.find(word);

        if (it == dictionary.end())
            cout << "eh" << endl;
        else
            cout << it->second << endl;
    }

    return 0;
}
