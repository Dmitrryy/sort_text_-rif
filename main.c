#include <stdio.h>
#include <stdlib.h>
#include "else.h"

int main() {
    char *text = 0;
    char **str_ptrs = 0;
    int lines = 0;

    FILE *f = fopen("C:\\Users\\dadro\\CLionProjects\\OneginV5\\text.txt", "rb");
    if (f == NULL) {
        printf("file not found");
        return 1;
    }

    text = getstr(f);

    fclose(f);

    change(text, &lines);

    str_ptrs = arr_point(text, lines);

    freopen("C:\\Users\\dadro\\CLionProjects\\OneginV5\\orig_text_chang.txt", "w", stdout);

    for (int i = 0; i < lines; i++)
        printf ("%s\n", str_ptrs[i]);

    qsort(str_ptrs, lines, sizeof(char **), compare);

    fclose(stdout);

    freopen("C:\\Users\\dadro\\CLionProjects\\OneginV5\\sort_text.txt", "w", stdout);

    for (int i = 0; i < lines; i++)
        printf ("%s\n", str_ptrs[i]);

    fclose(stdout);

    qsort(str_ptrs, lines, sizeof(char **), compare_rif);

    freopen("C:\\Users\\dadro\\CLionProjects\\OneginV5\\sort_text_rif.txt", "w", stdout);

    for (int i = 0, j = lines - 1; i < j; i++, j--) {
        printf("%s\n", str_ptrs[i]);
        printf("%s\n", str_ptrs[j]);
        if (i % (Size_Verse / 2) == 3)
            printf("\n");
    }
    fclose(stdout);

    free(text);
    free(str_ptrs);

    return 0;
}