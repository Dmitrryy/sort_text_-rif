#include "else.h"

void swop (void * elem1, void * elem2, size_t size) {

    static int  store_size = 0;
    static void * tmp = 0;

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