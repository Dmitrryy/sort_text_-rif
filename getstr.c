#include "else.h"
/**
 * Программа определяет размер файла и выделяет динамическую память под весь текст
 *
 * @param[in] f имя файла, с которого считывать данные
 * @return указатель на массив с текстом
 */
char* getstr (FILE *f) {
    assert (f != 0);

    unsigned long long len_all = 0;

    fseek(f, 0, SEEK_END);
    len_all = ftell(f);

    char *text = (char *) calloc(len_all + 1, sizeof(char));   ///выделение динамической памяти
    if (text == 0)
        return 0;

    fseek(f, 0, SEEK_SET);

    unsigned long long stat = fread (text, sizeof(char), len_all, f); ///stat - кол-во символов, которое было прочитано
    if (stat != len_all)   ///в случае несовпадения кол-ва символов в тексте с прочитанным кол-вом символом выдается предупреждение об ошибке считывания
        return 0;

    text[len_all] = '\0';

    return text;
}