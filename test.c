#include <stdio.h>
#include <stdbool.h>

bool backspaceCompare(char* s, char* t) {
    int skip1 = 0;
    int skip2 = 0;
    int i = strlen(s) - 1;
    int j = strlen(t) - 1;
    while (i >= 0 || j >= 0)
    {
        while (i >= 0)
        {
            if (s[i] == '#')
            {
                skip1++;
                i--;
            }
            else if (skip1 > 0)
            {
                skip1--;
                i--;
            }
            else break;
        }
        while (j >= 0)
        {
            if (t[j] == '#')
            {
                skip2++;
                j--;
            }
            else if (skip2 > 0)
            {
                skip2--;
                j--;
            }
            else break;
        }
        if (i >= 0 && j >= 0)
        {
            if (s[i] != t[j]) return false;
        }
        else if (i >= 0 || j >= 0) return false;
        i--;
        j--;
    }
    return true;
}