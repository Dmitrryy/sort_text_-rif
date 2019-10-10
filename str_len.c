int str_len (const char * str) {
    int len = 0;
    for (len = 0; str[len] != '\0'; len++)
        ;
    return len;
}
