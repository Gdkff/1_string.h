#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
    byte *res = S21_NULL;
    if (str != S21_NULL) {
        do {
            if (*str == (char)c) {
                res = (byte*)str;
                break;
            }
        } while (*str++ != '\0');
    }
    return (char*)res;
}
