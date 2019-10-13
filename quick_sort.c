#include "else.h"

//аналаг qsort
void quick_sort (void * ptr, size_t nom_elem, size_t size, int (*compare) (const void * , const void *)) {

    unsigned long long i = 0, j = nom_elem - 1;
    unsigned long long k = nom_elem / 2;
    unsigned long long centre = 0;
    static unsigned long long dep = 0;  //глубина рекурсии

    if (nom_elem <= 1) {
        dep--;
        return;
    }

    if (nom_elem <= 3) {  //если в массиве не больше 3 элементов не уходим в рекурсию
        for (unsigned long long f = 0; f < nom_elem - 1; f++)
            for (unsigned long long n = 0; n < nom_elem - 1 - f; n++)
                if (compare(ptr + n * size, ptr + (n + 1) * size) > 0) {
                    swop(ptr + n * size, ptr + (n + 1) * size, size);
                    dep--;
                }
        return;
    }
    while (i < k && j > k) {
        while (compare(ptr + i * size, ptr + k * size) < 0 && i < k && j != k)
            i++;
        while (compare(ptr + j * size, ptr + k * size) > 0 && j > k && i != k)
            j--;
        if (i != k && j != k) {
            swop(ptr + i * size, ptr + j * size, size);
            i++;
            j--;
        }
    }
    if (i == k) {
        while (compare(ptr + j * size, ptr + k * size) >= 0 && j > k)
            j--;
        swop (ptr + i * size, ptr + j * size, size);
        centre = j;
    }
    if (j == k) {
        while (compare(ptr + i * size, ptr + k * size) <= 0 && i < k)
            i++;
        swop (ptr + i * size, ptr + j * size, size);
        centre = i;
    }
    dep++;
    quick_sort (ptr + (centre + 1) * size, nom_elem - centre - 1, size, compare);
    quick_sort (ptr, centre, size, compare);
    if (dep == 0) {  //если глубина рекурсии снова 0, отправляем в swop нулевые данные для освобождения памяти после calloc
        swop(0, 0, 0);
        return;
    }
}