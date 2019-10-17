#include "else.h"

/**
 * @brief Меняет местами два элемента размера size
 *
 * @param[in,out] elem1 после выполнения функции = elem2
 * @param[in,out] elem2 после выполнения функции = elem1
 * @param[in] size размер одного элемента
 */
void swop (void * elem1, void * elem2, size_t size) {

    static int  store_size = 0;
    static void * tmp = 0;

    if (size == 0)
        if (tmp != 0){
            free (tmp);
            tmp = 0;
            return;
        }

    if (store_size != size) {
        store_size = size;
        if (tmp != 0)
            free (tmp);
        tmp = (void*) calloc (1, size);
    }

    memcpy (tmp, elem1, size);
    memcpy (elem1, elem2, size);
    memcpy (elem2, tmp, size);
}