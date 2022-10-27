#include "s21_string.h"
char *s21_strrchr(const char *str, int c) {
    char *res = S21_NULL;
    if (str != S21_NULL) {
        int i = 1;
        while (str[i - 1] != 0)
            i++;

        while (i-- != 0) {
            if (str[i] == (char)c) {
            res = (char *)str + i;
            break;
            }
        }
    }
    return res;
}
