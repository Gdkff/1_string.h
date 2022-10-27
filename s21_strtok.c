#include "s21_string.h"

int del_check(char c, const char *delim) {
    int res = 0;
    while (*delim != '\0') {
        if (c == *delim) res++;
        delim++;
    }
    return res;
}

char *s21_strtok(char *str, const char *delim) {
    if (delim == S21_NULL) {
        return S21_NULL;
    }
    static char *ptr;
    int flag = 0;
    char *ret = S21_NULL;
    if (!str) str = ptr;
    if (str) {
        while (1 && flag == 0) {
            if (del_check(*str, delim)) {
                str++;
                continue;
            }
            if (*str == '\0') flag = 1;
            break;
        }
        char *inter = str;
        while (1 && flag == 0) {
            if (*str == '\0') {
                ptr = str;
                ret = inter;
                flag = 1;
            }
            if (del_check(*str, delim)) {
                *str = '\0';
                ptr = str + 1;
                ret = inter;
                flag = 1;
            }
            str++;
        }
    }
    return ret;
}
