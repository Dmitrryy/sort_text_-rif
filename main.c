#include "else.h"

int main() {
    char *text = 0;
    int lines = 0;

    printf("||**********************************************||\n");
    printf("||The program sorts the text alphabetically.    ||\n");
    printf("||v5.3                                          ||\n");
    printf("||Made by Dmitry Drozdov                 10.2019||\n");
    printf("||                                 (C)for \"Ilab\"||\n");
    printf("||**********************************************||\n");

    FILE *f = fopen("C:\\Users\\dadro\\CLionProjects\\OneginV5\\text.txt", "rb");
    if (f == NULL) {
        printf("file not found");
        return 1;
    }
    text = getstr(f);  //выводим текст из вайла в массив
    if (text == 0) {
        printf ("error reading file\n");
        return 1;
    }
    fclose(f);

    change (text, &lines); //отправляем текст на изменения в change

    char** str_ptrs = arr_point (text, lines);  //создаем массив указателей

    char** str_ptrs_cpy = (char**) calloc (lines + 1, sizeof(char*));  //создаем массив для копии массива указателей
    assert (str_ptrs_cpy != 0);
    ptr_cpy (str_ptrs_cpy, str_ptrs);  //делаем копию указателей
    quick_sort (str_ptrs_cpy, lines, sizeof(char **), compare);  //сортируем текст по алфавиту
    //выводим результат в файл
    writer_text ("SORTED_TEXT", str_ptrs_cpy, 1, "C:\\Users\\dadro\\CLionProjects\\OneginV5\\CHANGE_TEXT.txt", "w");

    ptr_cpy (str_ptrs_cpy, str_ptrs);  //снова копируем
    quick_sort (str_ptrs_cpy, lines, sizeof(char **), compare_rif);  //сортируем по концу строк
    creat_rhyme (str_ptrs_cpy, lines);  //типа рифму создаем
    writer_text ("SORTED_RIF_TEXT", str_ptrs_cpy, Size_Verse, "C:\\Users\\dadro\\CLionProjects\\OneginV5\\CHANGE_TEXT.txt", "a");

    writer_text ("ORIG_CHANGE_TEXT", str_ptrs, 1, "C:\\Users\\dadro\\CLionProjects\\OneginV5\\CHANGE_TEXT.txt", "a");

    free(text);
    free(str_ptrs);
    free(str_ptrs_cpy);

    return 0;
}