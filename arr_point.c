#include "else.h"

/**
 * @brief Функция для создания массива указателей на начало каждой строки
 *
 * Предусмотренно, что не создвется указатель на пустую строку
 * @code
 * if (isalpha(text[i]) != 0) {
                    stat = 0;
                    str_ptrs[k++] = &text[i];
                }
 * @endcode
 *
 * @param[in] text - текст, для которого создается массив указателей
 * @param[in] lines - кол-во строк в тексте
 * @return указатель на первый элемент массива указателей
 */
char** arr_point (char * text, const int lines) {
    char **str_ptrs = (char **) calloc(lines + 1, sizeof(char *));
    assert (str_ptrs != 0);

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