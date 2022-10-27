#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    s21_size_t i = 0;
    int res = 0;
    if (str1 != S21_NULL && str2 != S21_NULL) {
        do {
            res = *str1 - *str2;
        } while (*str1 == *str2 && *str1++ != '\0' && *str2++ != '\0' && ++i != n);
    }
    return res;
}
