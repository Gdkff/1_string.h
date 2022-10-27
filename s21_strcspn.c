#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    if (str1 == S21_NULL || str2 == S21_NULL)
        return -1;

    s21_size_t len1 = s21_strlen(str1);
    s21_size_t len2 = s21_strlen(str2);
    int res = 0;
    int is_found = 0;

    for (s21_size_t i = 0; i < len1; i++) {
        is_found = 0;
        for (s21_size_t j = 0; j < len2; j++) {
            if (str1[i] == str2[j])
                is_found = 1;
        }
        if (is_found) {
            break;
        }
        res++;
    }
    return res;
}
