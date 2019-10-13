#include "else.h"

void writer_text (const char * ad, char ** text, int size_verse, const char * file, const char * mode) {

    freopen(file, mode, stdout);
    printf ("\n\n**********%s**********\n\n", ad);

    for (int i = 0, k = 1; text[i] != 0; i++, k++) {
        printf("%s\n", text[i]);
        if (k % size_verse == 0 && size_verse != 1)
            printf ("\n");
    }
    fclose(stdout);
}