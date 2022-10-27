#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
    void *res = str;
    if (str != S21_NULL) {
        byte * p = (byte*) str;
        while (n--) {
            *p = c;
            p++;
        }
    }
    return res;
}
