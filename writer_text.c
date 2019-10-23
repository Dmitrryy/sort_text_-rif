#include "else.h"
/**
 * @brief Функция для вывода массива с текстом в файл
 *
 * @param[in] ad - заголовок, который распечатается перед текстом
 * @param[in] text - текст, который необходимо вывести в файл
 * @param[in] size_verse - при необходимости распечатать куплетами, указать размер. В ином случае равен 1
 * @param[in] file - куда выводить текст
 * @param[in] mode - в каком режиме открывается текст
 */
void writer_text (const char * ad, char ** text, int size_verse, const char * file, const char * mode) {
    assert (text != 0);
    assert (file != 0);

    freopen(file, mode, stdout);
    printf ("\n\n**********%s**********\n\n", ad);

    for (int i = 0, k = 1; text[i] != 0; i++, k++) {
        printf("%s\n", text[i]);
        if (k % size_verse == 0 && size_verse != 1)
            printf ("\n");
    }
    fclose(stdout);
}