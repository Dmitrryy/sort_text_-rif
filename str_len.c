int str_len (const char * str) {
    int len = 0;
    for (len = 0; str[len] != '\0'; len++)
        ;
    return len;
}

void ptr_cpy (char** ptr1, const char ** ptr2) {
    for (int i = 0; ptr2[i] != 0; i++)
        ptr1[i] = ptr2[i];
}