#include "else.h"

int compare_rif (const void * str1, const void * str2) {
    int stat = 0;
    int k = 0, j = 0;
    char ** strx = (char**)str1;
    char ** stry = (char**)str2;

    /*for ( ; (*strx)[k] != '\0'; k++)
        ;
    for ( ; (*stry)[j] != '\0'; j++)
        ;*/
    k = str_len(*strx);
    j = str_len(*stry);

    while ((k >=0 ) && (j >= 0) && (stat <= Rhyme_Size)) {
        for ( ; (*strx)[k] < 'a' || (*strx)[k] > 'z'; ) {
            k--;
            if (k < 0)
                break;
        }
        for ( ; (*stry)[j] < 'a' || (*stry)[j] > 'z'; ) {
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