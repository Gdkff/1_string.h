#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
    int res = 0;
    if (str1 != S21_NULL && str2 != S21_NULL) {
        byte* s1 = (byte*)str1;
        byte* s2 = (byte*)str2;
        while (*s1 == *s2) {
            if (*s1 == '\0') {
                break;
            }
            s1++; s2++;
        }
        res = *s1 - *s2;
    }
    return res;
}
