#include "else.h"

///программа, создающая массив указателей на начала строк
char** arr_point (char * text, const int lines) {
    char **str_ptrs = (char **) calloc(lines + 1, sizeof(char *));

    int stat = 1;
    int k = 0;


    for (int i = 0; k < lines; i++) {
        if (text[i] != '\0')
            if (stat != 0)
                if (isalpha(text[i]) != 0) {
                    stat = 0;
                    str_ptrs[k++] = &text[i];
                }
        if (text[i] == '\0') {
            stat = 1;
        }
    }
    return str_ptrs;
}