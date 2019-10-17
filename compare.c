#include "else.h"

/**
 * @brief Функция, сравнивающая две строки
 *
 * Функция умеет пропускать все, что не буква, то есть не ломается на первом же знакепрепинания.
 *
 * @param[in] strx - первый сравниваемый элемент
 * @param[in] stry - второй сравниваемый элемент
 * @return возвращает 1, 0, -1, если первый элемент больше, равен, меньше второго соответственно
 */
int compare (const void * strx, const void * stry) {
    int k = 0, j = 0;
    char ** strx1 = (char**)strx;
    char ** stry1 = (char**)stry;
    unsigned long long k_len = strlen(*strx1);
    unsigned long long j_len = strlen(*stry1);

    while (((*strx1)[k] != '\0') && ((*stry1)[j] != '\0')) {
        for ( ; isalpha ((*strx1)[k]) == 0; ) {
            k++;
            if (k >= k_len)
                break;
        }
        for ( ; isalpha ((*stry1)[j]) == 0; ) {
            j++;
            if (j >= j_len)
                break;
        }
        if ((*strx1)[k] > (*stry1)[j])
            return 1;
        if ((*strx1)[k] == (*stry1)[j]) {
            k++;
            j++;
        }
        if ((*strx1)[k] < (*stry1)[j])
            return -1;
    }
    return 0;
}
