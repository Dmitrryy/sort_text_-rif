void ptr_cpy (char** ptr1, char ** ptr2) {
    for (int i = 0; ptr2[i] != 0; i++)
        ptr1[i] = (char*)ptr2[i];
}