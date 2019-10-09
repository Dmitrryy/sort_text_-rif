void change (char* str, int *lines) {
    int stat1 = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A') && (str[i] <= 'Z'))
            str[i] += 32;
        if (str[i] == '\r')
            str[i] = '\n';
        if (str[i] == '\n')
            if (stat1 == 1) {
                (*lines)++;
                stat1 = 0;
            }
        if (str[i] != '\n')
            if (stat1 == 0)
                if ((str[i] >= 'a') && (str[i] <= 'z'))
                    stat1 = 1;
    }
    (*lines)++;

    for (int i = 0; str[i] != '\0';) {
        if (str[i] != '\n')
            i++;
        if (str[i] == '\n') {
            str[i] = '\0';
            i++;
        }
    }
}