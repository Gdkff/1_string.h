#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    int res = 0;
    if (str1 != S21_NULL && str2 != S21_NULL) {
        for (s21_size_t i = 0; i < n; i++) {
            res = ((byte*)str1)[i] - ((byte*)str2)[i];
            if (res != 0) break;
        }
    }
    return res;
}
