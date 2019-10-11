#include "else.h"

void quick_sort (void * ptr, size_t nom_elem, size_t size, int (*compare) (const void * , const void *)) {

    unsigned long long i = 0, j = nom_elem - 1;
    unsigned long long k = rand() % nom_elem;
    unsigned long long centre = 0;

    if (nom_elem <= 3) {
        for (unsigned long long f = 0; f < nom_elem - 1; f++)
            for (unsigned long long n = 0; n < nom_elem - 1 - f; n++)
                if (compare(&(ptr[n]), &(ptr[n + 1])) == 1)
                    swop(&(ptr[n]), &(ptr[n + 1]), size);
        return;
    }
    while (i <= k && j >=k) {
        while (compare (ptr + i, ptr + k) >= 0 && i <= k)
            i++;
        while (compare (&(ptr[j]), &(ptr[k])) <= 0 && j >= k)
            j--;
        if (i != k && j != k) {
            swop(&(ptr[i]), &(ptr[j]), size);
            i++;
            j--;
        }
        if (i == k) {
            swop (&(ptr[i]), &(ptr[j]), size);
            centre = j;
        }
        if (j == k) {
            swop (&(ptr[i]), &(ptr[j]), size);
            centre = i;
        }
    }
    quick_sort (&ptr[centre + 1], nom_elem - centre, size, compare);
    quick_sort (&ptr[0], centre - 1, size, compare);
}