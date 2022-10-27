#include "s21_string.h"

// "Hello world", 'w', 6
void *s21_memchr(const void *str, int c, s21_size_t n) {
    void *res = S21_NULL;
    if (str != S21_NULL) {
        for (void *p = (void *)str; p - str < (long)n; p += sizeof(byte)) {
            if (*(byte*)p == c) {
                res = p;
                break;
            }
        }
    }
    return res;
}
