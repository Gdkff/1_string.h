#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *res = dest;
    if (dest != S21_NULL) {
        int i = 0;
        int j = 0;
        while (*(char*)(dest+i) != '\0') i++;
        while (*(char*)(src+j) != '\0' && j < (int)n) {
            dest[i] = src[j];
            i++;
            j++;
        }
        dest[i] = '\0';
    }
    return res;
}
