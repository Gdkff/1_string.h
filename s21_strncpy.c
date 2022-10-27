#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    char *res = dest;
    if (dest != S21_NULL && src != S21_NULL) {
        s21_size_t i = 0;
        do {
            *dest++ = *src;
        } while (*src++ != '\0' && i++ < n);
    }
    return res;
}
