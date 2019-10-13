#include "else.h"

//выводим строку в один большей массив
char* getstr (FILE *f) {
    unsigned long long len_all = 0;

    fseek(f, 0, SEEK_END);
    len_all = ftell(f);

    char *text = (char *) calloc(len_all + 1, sizeof(char));
    if (text == 0)
        return 0;

    fseek(f, 0, SEEK_SET);

    unsigned long long stat = fread (text, sizeof(char), len_all, f);
    if (stat != len_all)
        text = 0;
    text[len_all] = '\0';

    return text;
}