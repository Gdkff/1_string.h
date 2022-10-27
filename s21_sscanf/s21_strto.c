#include "s21_sscanf.h"
#include "../s21_string.h"

int is_digit(int c) {
    return c >= '0' && c <= '9';
}

int is_alpha(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int is_upper(int c) {
    return c >= 'A' && c <= 'Z';
}

int s21_atoi(const char *str) {
    if (str == 0) return 0;
    const char *s = str;
    int c;

    int res = 0;
    int neg = 0;

    // пропуск первых пробелов
    while (*s == ' ') {
        s++;
    }

    // проверка знака
    if (*s == '-') {
        neg = 1;
        s++;
    } else if (*s == '+') {
        s++;
    }

    while ((c = *s++) >= '0' && c <= '9') {
        res *= 10;
        res += c - '0';
    }

    res = neg ? -res : res;
    return res;
}

long s21_strtol(const char *str, char **end, int base) {
    const char *s = str;
    int c;
    int sign = 1;
    long res = 0;

    // пропуск первых пробелов
    while (*s == ' ') {
        s++;
    }
    // проверка знака
    if (*s == '-') {
        sign = -1;
        s++;
    } else if (*s == '+') {
        s++;
    }
    // проверка на 0x и 0 для hex и oct
    if (*s == '0') {
        if (base == 8) s++;
        if (base == 16) {
            if (s[1] == 'x' || s[1] == 'X')
                s += 2;
        }
    }

    while ((c = *s++) != '\0') {
        // превращаем 'c' в нормальное число от 0
        if (is_digit(c)) {
            c -= '0';
        } else if (is_alpha(c)) {
            if (is_upper(c))
                c -= 'A' - 10;
            else
                c -= 'a' - 10;
        } else {
            break;
        }

        if (c < base) {
            res *= base;
            res += c;
        } else {
            break;
        }
    }
    if (end != S21_NULL)
        *end = (char*)s - 1;
    res *= sign;
    return res;
}

unsigned long s21_strtoul(const char *str, char **end, int base) {
    const char *s = str;
    int c;
    int sign = 1;
    unsigned long res = 0;

    // пропуск первых пробелов
    while (*s == ' ') {
        s++;
    }
    // проверка знака
    if (*s == '-') {
        sign = -1;
        s++;
    } else if (*s == '+') {
        s++;
    }
    // проверка на 0x и 0 для hex и oct
    if (*s == '0') {
        if (base == 8) s++;
        if (base == 16) {
            if (s[1] == 'x' || s[1] == 'X')
                s += 2;
        }
    }

    while ((c = *s++) != '\0') {
        // превращаем 'c' в нормальное число от 0
        if (is_digit(c)) {
            c -= '0';
        } else if (is_alpha(c)) {
            if (is_upper(c))
                c -= 'A' - 10;
            else
                c -= 'a' - 10;
        } else {
            break;
        }

        if (c < base) {
            res *= base;
            res += c;
        } else {
            break;
        }
    }
    if (end != S21_NULL)
        *end = (char*)s - 1;
    res *= sign;
    return res;
}

double s21_strtod(const char *str, char **end) {
    double res = 0.0;
    // int assigned = 0;
    int exp = 0;
    int sign = 1;

    const char *s = str;
    int c;
    // пропуск первых пробелов
    while (*s == ' ') {
        s++;
    }
    // проверка знака
    if (*s == '-') {
        sign = -1;
        s++;
    } else if (*s == '+') {
        s++;
    }
    // читаем целую часть
    while ((c = *s++) != '\0' && is_digit(c)) {
        res *= 10;
        res += c - '0';
    }
    // если попався '.' (даже без целой части)
    if (c == '.') {
        while ((c = *s++) != '\0' && is_digit(c)) {
            res *= 10;
            res += c - '0';
            exp--;
        }
    }
    // если попався 'e' (даже без целой и дробной части числа)
    if (c == 'e' || c == 'E') {
        int i = 0;
        int e_sign = 1;

        if (*s == '-') {
            e_sign = -1;
            s++;
        } else if (*s == '+') {
            s++;
        }

        while ((c = *s++) != '\0' && is_digit(c)) {
            i *= 10;
            i += c - '0';
        }
        exp += e_sign * i;
    }

    while (exp > 0) {
        res *= 10;
        exp--;
    }
    while (exp < 0) {
        res *= 0.1;
        exp++;
    }
    if (end != S21_NULL)
        *end = (char*)s - 1;
    res *= sign;
    return res;
}

long double s21_strtold(const char *str, char **end) {
    long double res = 0.0;
    int exp = 0;
    int sign = 1;

    const char *s = str;
    int c;
    // пропуск первых пробелов
    while (*s == ' ') {
        s++;
    }
    // проверка знака
    if (*s == '-') {
        sign = -1;
        s++;
    } else if (*s == '+') {
        s++;
    }
    // читаем целую часть
    while ((c = *s++) != '\0' && is_digit(c)) {
        res *= 10;
        res += c - '0';
    }
    // если попався '.' (даже без целой части)
    if (c == '.') {
        while ((c = *s++) != '\0' && is_digit(c)) {
            res *= 10;
            res += c - '0';
            exp--;
        }
    }
    // если попався 'e' (даже без целой и дробной части числа)
    if (c == 'e' || c == 'E') {
        int i = 0;
        int e_sign = 1;

        if (*s == '-') {
            e_sign = -1;
            s++;
        } else if (*s == '+') {
            s++;
        }

        while ((c = *s++) != '\0' && is_digit(c)) {
            i *= 10;
            i += c - '0';
        }
        exp += e_sign * i;
    }

    while (exp > 0) {
        res *= 10;
        exp--;
    }
    while (exp < 0) {
        res *= 0.1;
        exp++;
    }
    if (end != S21_NULL)
        *end = (char*)s - 1;
    res *= sign;
    return res;
}
