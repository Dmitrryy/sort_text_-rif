#include "else.h"

///типа создатель рифм))
void creat_rhyme (char ** text, int lines) {

    char** copy_text = (char**) calloc (lines + 1, sizeof(char*));
    ptr_cpy(copy_text, text);

    for (int i = 0, j = lines - 1, k = 0; i < j; ) {
        text[k++] = copy_text[i++];
        text[k++] = copy_text[j--];
    }
}