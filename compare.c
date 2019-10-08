int compare (const void * strx, const void * stry) {
    int k = 0, j = 0;
    char ** strx1 = (char**)strx;
    char ** stry1 = (char**)stry;

    while (((*strx1)[k] != '\0') && ((*stry1)[j] != '\0')) {
        for ( ; (*strx1)[k] < 'a' || (*strx1)[k] > 'z'; )
            k++;
        for ( ; (*stry1)[j] < 'a' || (*stry1)[j] > 'z'; )
            j++;
        if ((*strx1)[k] > (*stry1)[j])
            return 1;
        if ((*strx1)[k] == (*stry1)[j]) {
            k++;
            j++;
        }
        if ((*strx1)[k] < (*stry1)[j])
            return -1;
    }
    return 0;
}
