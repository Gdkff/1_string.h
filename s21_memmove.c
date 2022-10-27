#include "s21_string.h"

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    void *res = dest;
    if (dest != S21_NULL && src != S21_NULL) {
        if (dest < src) {
            byte *d = (byte *) dest;
            byte *s = (byte *) src;
            while (n--) {
                *d = *s;
                d++; s++;
            }
        } else {
            byte *d = (byte *)(dest + n - 1);
            byte *s = (byte *)(src + n - 1);
            while (n--) {
                *d = *s;
                --d;
                --s;
            }
        }
    }
    return res;
}
