#include "else.h"

///сравнивает строки по их концу
int compare_rif (const void * str1, const void * str2) {
    int stat = 0;
    unsigned long long k = 0, j = 0;
    char ** strx = (char**)str1;
    char ** stry = (char**)str2;

    k = strlen(*strx);
    j = strlen(*stry);

    while ((k >=0 ) && (j >= 0) && (stat <= Rhyme_Size)) {
        for ( ; isalpha((*strx)[k]) == 0; ) {
            k--;
            if (k < 0)
                break;
        }
        for ( ; isalpha((*stry)[j]) == 0; ) {
            j--;
            if (j < 0)
                break;
        }
        if ((*strx)[k] > (*stry)[j])
            return -1;
        if ((*strx)[k] == (*stry)[j]) {
            k--;
            j--;
            stat++;
            if ((k < 0) || (j < 0))
                break;
        }
        if ((*strx)[k] < (*stry)[j])
            return 1;
    }
    return 0;
}