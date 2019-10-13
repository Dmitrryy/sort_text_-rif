#include "else.h"

//заменяет '\r' и '\n' на '\0' и считает кол-во строк (не считая аустые строки)
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