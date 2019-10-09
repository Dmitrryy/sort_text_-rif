#include <stdio.h>
#include <stdlib.h>

char* getstr (FILE *f) {
    int long len_all = 0;

    fseek(f, 0, SEEK_END);

    len_all = ftell(f);

    char *text = (char *) calloc(len_all + 1, sizeof(char));

    fseek(f, 0, SEEK_SET);

    freopen("C:\\Users\\dadro\\CLionProjects\\oneginV5\\text.txt", "rb", stdin);

    scanf("%[^\0]", text);

    return text;
}