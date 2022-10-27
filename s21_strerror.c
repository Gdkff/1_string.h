#include "s21_string.h"
#include <stdio.h>

char *s21_strerror(int errnum);
char *s21_convert_from_int(int num);
void s21_reverse_str(char *dest, char *str);

char *s21_strerror(int errnum) {
    static char res[100] = {0};
    ARRAY;
    char str[100] = ERROR;
    int flag = 0;
    for (int i = 0; i < ERR_MAX; i++) {
        if (errnum == i) {
            s21_strcpy(res, errlist[i]);
            flag = -1;
        }
    }
    if (flag == 0) {
        char *errnum_str = s21_convert_from_int(errnum);
        char *tmp = s21_strcat(str, errnum_str);
        s21_strcpy(res, tmp);
    }
    return res;
}

char *s21_convert_from_int(int num) {
    char tmp[20];
    static char result[20];
    int i = 0;
    int n = num;
    while (n != 0) {
        if (n < 0) {
            tmp[i] = (n * (-1) % 10) + '0';
        } else {
            tmp[i] = (n % 10) + '0';
        }
        n /= 10;
        i++;
    }
    if (num < 0) {
        tmp[i++] = '-';
    }
    tmp[i] = '\0';
    s21_reverse_str(result, tmp);
    return result;
}

void s21_reverse_str(char *dest, char *str) {
    s21_size_t len = s21_strlen(str);
    s21_size_t i = 0;
    for (s21_size_t j = len - 1; i < len; i++, j--) {
        dest[i] = str[j];
    }
    dest[i] = '\0';
}
