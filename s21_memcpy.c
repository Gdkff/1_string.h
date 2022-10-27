#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    void *res = dest;
    if (dest != S21_NULL && src != S21_NULL) {
        byte *s = (byte*)src;
        byte *d = (byte*)dest;
        while (n--) {
            *d = *s;
            d++;
            s++;
        }
    }
    return res;
}
