#include "s21_string.h"

char *s21_strcpy(char *s1, const char *s2) {
    char *res = s1;
    if (s1 != S21_NULL && s2 != S21_NULL) {
        char *s = s1;
        for (; (*s++ = *s2++) != '\0';) {}
    }
    return res;
}
