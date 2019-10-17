#include "else.h"

/**
 * @brief Функция для подготовки текста к сортировке
 *
 * Заменяет все '\r'(если есть) и '\n' на '\0'
 * Заменяет заглавные буквы на строчные и считает кол-во не пустых строк
 *
 * @param[in, out] str - текст для изменений
 * @param[out] lines - кол-во не пустных строк
 */
void change (char* str, int *lines) {
    int stat1 = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = (char)tolower(str[i]);
        if (str[i] == '\r')
            str[i] = '\0';
        if (str[i] == '\0')
            if (stat1 == 1) {
                (*lines)++;
                stat1 = 0;
            }
        if (str[i] != '\0')
            if (stat1 == 0)
                if (isalpha(str[i]) != 0)
                    stat1 = 1;
    }
    (*lines)++;
}