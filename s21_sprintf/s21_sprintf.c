#include <wchar.h>
#include <math.h>
#include <stdarg.h>
#include "../s21_string.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
int ss21_strlen(char *str);

typedef struct s_spec {
    char spec;  // f, c, d, i, u, s, %
    char flags;  // +, ' '
    char flag_minus;  // 0, \0
    int width;
    int precision;
    char len;  // h, l
}   t_spec;

void  int_to_string(char *str, long int num) {
    int x = 0, len = 0, start = 0;
    if (num < 0) {
        *str = '-';
        start = 1;
        len++;
    } else if (num == 0) {
        len++;
        *str = '0';
    }
    if (num < 0) {
        for (long int temp_num = num; temp_num <= -1; temp_num /= 10) {
            len++;
        }
    } else {
        for (long int temp_num = num; temp_num >= 1; temp_num /= 10) {
            len++;
        }
    }
    str[len] = '\0';
    for (int i = len - 1; i >= start; i--) {
        x = num < 0 ? -(num % 10) : num % 10;
        str[i] = x + '0';
        num /= 10;
    }
}

void structnull(t_spec *info) {
    info->spec = 0;
    info->flags = 0;
    info->flag_minus = 0;
    info->width = 0;
    info->precision = -1;
    info->len = 0;
}


int find_char_in_string(char *s, char let) {
    int res = 0;
    for (; *s; s++) {
        if (*s == let) {
            res = 1;
            break;
        }
    }
    return res;
}


void float_part_to_string(char *float_part, long double num, int accurary) {
    // printf("accurary %d' num %.10Lf'\n", accurary, num);
    int i = 0;
    for (; i < accurary + 1; i++) {
        float_part[i] = (int)(num * 10) + '0';
        num = (num * 10) - (int)(num * 10);
    }
    float_part[i] = '\0';
}

int round_float_str(char *str, int accurary) {
    // printf("\nдебуга: %s'%d'\n", str, accurary);
    int len = 0, start = 0;
    int flen = 0;

    for (int is_dot = 0; str[len]; len++) {
        if (is_dot) {
            flen++;
        }
        if (str[len] == '.') is_dot = 1;
    }
    int dlen = len - flen - 1;
    int tmp = flen > accurary? accurary : flen;
    int last_num_i = dlen + tmp;
    // printf("\nteempe %d\n", tmp);
    if (tmp >= 2) {
        if (str[last_num_i + 1] >= '5' && str[last_num_i + 1] <= '9') {
            str[last_num_i]++;
        }
        for (int i = last_num_i - 1; str[i] != '.'; i--) {
            if (str[i + 1] >= '9' + 1) {
                str[i + 1] = '0';
                str[i]++;
            }
        }
    } else if (tmp == 1) {
        if (str[last_num_i + 1] >= '5' && str[last_num_i + 1] <= '9') {
            str[last_num_i]++;
        }
        if (str[last_num_i] >= '9' + 1) {
            str[last_num_i] = '0';
            // str[last_num_i - 2]++;
        }
    } else if (tmp == 0) {
        if (str[last_num_i + 1] >= '5' && str[last_num_i + 1] <= '9') {
            str[last_num_i] = '\0';
            // str[last_num_i - 1]++;
        }
    }
    str[last_num_i + 1] = '\0';
    if (find_char_in_string("+- ", str[0])) {
        start = 1;
    }
    int i = start + 1;
    if (str[start] == '0') {
        for (; str[i]; i++) {
            str[i - 1] = str[i];
        }
        str[i - 1] = '\0';
    }
    if (str[i - 2] == '.') {
        str[i - 2] = '\0';
        i--;
    }
    return i - 1;
}

void load_sign(long double *num, char *sign, int *len_sign, t_spec spec) {
    if (*num < 0) {
        *sign = '-';
        *len_sign = 1;
        *num = -*num;
    } else if (spec.flags == '+') {
        *sign = '+';
        *len_sign = 1;
    } else if (spec.flags == ' ') {
        *sign = ' ';
        *len_sign = 1;
    }
}

int length_int_part(long double num) {
    int len_int_part = 0;
    for (long int num_temp = num; num_temp >= 1; (num_temp /= 10)) {
        len_int_part++;
    }
    if ((long int)num == 0) {
        len_int_part++;
    }
    return len_int_part;
}

void fill_width(char *str, char *num_str, t_spec spec, int num_len) {
    int width_fill_len = 0;
    if (spec.width > num_len) {
        width_fill_len = spec.width - num_len;
    }
    int i = 0, j = 0;
    for (; i < num_len + width_fill_len; i++) {
        if (spec.flag_minus == '-') {
            if (i < num_len) {
                str[i] = num_str[j++];
            } else {
                str[i] = ' ';
            }
        } else {
            if (i < width_fill_len) {
                str[i] = ' ';
            } else {
                str[i] = num_str[j++];
            }
        }
    }
    str[i] = '\0';
}


int format_operating(char *str, long double num, t_spec spec) {
    char num_str[201];
    s21_memset(num_str, '0', 200);
    num_str[200] = '\0';
    int len_sign = 0, num_len = 0;
    char sign = '\0';
    if (spec.precision == -1) {
        spec.precision = 6;
    }
    load_sign(&num, &sign, &len_sign, spec);
    if (sign) {
        num_str[0] = sign;
    }
    // float nearest = roundf(val * 100) / 100;
    long int num_int_part = round(num * (int)pow(10, spec.precision)) / (int)pow(10, spec.precision);
    long double num_float_part = num - num_int_part;  // тут приколдэс
    // printf("num_float_part %.10Lf' num %.10Lf' num_i_part %ld\n", num_float_part, num, num_int_part);
    int len_int_part = length_int_part(num);



    int_to_string(num_str + 1 + len_sign, num_int_part);
    num_str[len_int_part + 1 + len_sign] = '.';
    // printf("debuga %d\n", len_int_part);
    float_part_to_string(num_str + len_int_part + 2 + len_sign, num_float_part,
                        spec.precision);

    // printf("spec prec2=%d\n", spec.precision);
    num_len = round_float_str(num_str, spec.precision);
    fill_width(str, num_str, spec, num_len);
    int str_len = 0;
    for (; str[str_len]; str_len++) {}
    str[str_len] = '\0';
    return str_len -1;
}

int pow2(int a, int b) {
    int answ = a;
    if (b == 0) {
        answ = 1;
    } else {
        for (; b - 1 > 0; b--) {
        answ *= a;
        }
    }
    return answ;
}

int convert_numstring_to_int(char *p, int *num) {
    int n = 0;
    for (char *p2 = p; *p2 >= '0' && *p2 <= '9'; p2++) {
        n++;
    }
    int sch = 0;
    *num = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (p[i] != 0) {
            *num += (p[i] - 48) * pow2(10, sch++);
        }
    }
    return n - 1;
}


int format_f(char *str, va_list *arg, t_spec info) {
    long double num = 0;
    // char final[800] = {0};
    // char int_part[800] = {0};
    // char fr_part[800] = {0};
    num = (double)va_arg(*arg, double);

    return format_operating(str, num, info);
}

long int max(long long int a, long long int b) {
    long int res = 0;
    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;
    if (a >= b)
        res = a;
    else
        res = b;
    return res;
}

long int intlen(long long int a) {
    long int res = 0;
    if (a == 0)
        res = 1;
    if (a < 0) {
        a *= -1;
        res++;
    }
    for (; a > 0; a /= 10, res++) {}
    return res;
}

long int intlen_u(long long int a) {
    long int res = 0;
    if (a == 0)
        res = 1;
    if (a < 0) {
        a *= -1;
    }
    for (; a > 0; a /= 10, res++) {}
    return res;
}

int format_d(char *str, va_list *arg, t_spec info) {
    long int num = 0;
    long int final_size = 0;
    short int is_minus = 0;
    char final[800] = {0};
    char strnum[800] = {0};
    short int is_prec_z = 0;

    if (info.len == 'l')
        num = va_arg(*arg, long int);
    if (info.len == 'h')
        num = (short)va_arg(*arg, int);
    else if (!info.len)
        num = (int)va_arg(*arg, int);
    if (info.precision == 0)
        is_prec_z = 1;
    if (info.precision == -1)
        info.precision = 0;
    final_size = max(info.width, info.precision);
    final_size = max(final_size, intlen(num));
    long int strnum_len = max(info.precision, intlen_u(num));
    if (num < 0 || info.flags) {
        if (num < 0) {
            num *= -1;
            is_minus = 1;
        }
        strnum_len++;
    }
    s21_memset(final, '\0', final_size + 1);
    s21_memset(final, ' ', final_size);
    s21_memset(strnum, '\0', strnum_len + 1);
    s21_memset(strnum, '0', strnum_len);
    if (num == 0 && is_prec_z == 1) {
        strnum[0] = '\0';
    } else {
        for (int i = strnum_len; num > 0; i--) {
            strnum[i - 1] = (num % 10) + '0';
            num /= 10;
        }
    }
    if (is_minus || info.flags) {
        if (is_minus)
            strnum[0] = '-';
        if (info.flags && !is_minus)
            strnum[0] = info.flags;
    }
    if (!info.width || (info.width <= strnum_len))
        s21_strcpy(final, strnum);
    if (info.width > strnum_len && !info.flag_minus) {
        s21_strcpy(&final[info.width - s21_strlen(strnum)], strnum);
    }
    if (info.width > strnum_len && info.flag_minus == '-') {
        s21_memcpy(final, strnum, strnum_len);
    }
    int j = 0;
    for (; final[j]; j++) {
        str[j] = final[j];
    }
    str[j] = '\0';
    return j;
}

int format_u(char *str, va_list *arg, t_spec info) {
    unsigned long int num = 0;
    long int final_size = 0;
    char final[800] = {0};
    char strnum[800] = {0};

    if (info.len == 'l')
        num = va_arg(*arg, unsigned long int);
    if (info.len == 'h')
        num = (unsigned short)va_arg(*arg, unsigned int);
    else if (!info.len)
        num = (unsigned int)va_arg(*arg, unsigned int);
    if (info.precision == -1)
        info.precision = 0;
    final_size = max(info.width, info.precision);
    final_size = max(final_size, intlen(num));
    long int strnum_len = max(info.precision, intlen_u(num));
    s21_memset(final, '\0', final_size + 1);
    s21_memset(final, ' ', final_size);
    s21_memset(strnum, '\0', strnum_len + 1);
    s21_memset(strnum, '0', strnum_len);
    for (int i = strnum_len; num > 0; i--) {
        strnum[i - 1] = (num % 10) + '0';
        num /= 10;
    }
    if (!info.width || (info.width <= strnum_len))
        s21_strcpy(final, strnum);
    if (info.width > strnum_len && !info.flag_minus) {
        s21_strcpy(&final[info.width - s21_strlen(strnum)], strnum);
    }
    if (info.width > strnum_len && info.flag_minus == '-') {
        s21_memcpy(final, strnum, strnum_len);
    }
    int j = 0;
    for (; final[j]; j++) {
        str[j] = final[j];
    }
    str[j] = '\0';
    return j;
}


int format_c(char *str, va_list *arg, t_spec info, int len) {
    char res[800] = {0};
    char c;
    wint_t wc;

    s21_memset(res, '\0', info.width + 2);
    if (info.len == 'l') {
        wc = va_arg(*arg, wint_t);
        c = (char)wc;
    } else {
        c = (char)va_arg(*arg, int);
    }
    if (info.width) {
        s21_memset(res, ' ', info.width);
    }
    if (info.flag_minus == '-' || info.width == 0) {
        res[0] = c;
    } else {
        res[info.width - 1] = c;
    }
    int i = 0;
    if (!c) {
        i++;
    }
    for (; res[i]; i++) {
        str[len + i] = res[i];
    }
    str[len + i] = '\0';
    return i;
}

int w21_strlen(wchar_t *str) {
    if (!(*str))
        return 0;
    int i = 0;
    for (; str[i]; i++) {}
    return i;
}

int ss21_strlen(char *str) {
    int res = 0;
    if (!str)
        return res;
    while (str[res])
        res++;
    return res;
}

int format_s(char *str, va_list *arg, t_spec info) {
    char *strarg = S21_NULL;
    wchar_t *wstrarg = S21_NULL;
    int str_size = 0;
    int final_size = 0;
    char norm_str[800] = {0};
    char final[800] = {0};

    if (info.len == 'l') {
        wstrarg = va_arg(*arg, wchar_t *);
        str_size = w21_strlen(wstrarg);
    } else {
        strarg = va_arg(*arg, char *);
        str_size = s21_strlen(strarg);
    }
    if (info.precision >= 0 && str_size > info.precision) {
        str_size = info.precision;
    }
    s21_memset(norm_str, '\0', str_size + 1);
    if (info.len == 'l') {
        for (int i = 0; i < str_size; i++) {
            norm_str[i] = (char)wstrarg[i];
        }
    } else {
        for (int i = 0; i < str_size; i++) {
            norm_str[i] = strarg[i];
        }
    }
    final_size = max(info.width, str_size);
    s21_memset(final, '\0', final_size + 1);
    s21_memset(final, ' ', final_size);
    if (!info.flag_minus) {
        s21_strcpy(&final[final_size - str_size], norm_str);
    } else {
        s21_memcpy(final, norm_str, str_size);
    }

    int j = 0;
    for (; final[j]; j++) {
        str[j] = final[j];
    }
    str[j] = '\0';
    return j;
}
int check_format(int c) {
    int ret = 0;
    if (s21_strchr("fcdisu%+- hl.", c) || isdigit(c))
        ret = 1;
    return ret;
}

int parsing(char *str, const char *format, t_spec info, va_list *a) {
    int len = 0;
    int flag = 0;
    for (int i = 0; format[i];) {
        if (format[i] == '%' && format[i + 1] && check_format(format[i + 1])) {
            i++;
            flag = 0;
            structnull(&info);
            while (!flag) {
                if (isdigit(format[i])) {
                    for (; isdigit(format[i]); i++) {
                        info.width = (info.width * 10) + (format[i] - '0');
                    }
                }
                if (format[i] == '.') {
                    i++;
                    info.precision = 0;
                    for (; isdigit(format[i]); i++) {
                        info.precision = (info.precision * 10) + (format[i] - '0');
                    }
                }
                if (format[i] == '-') {
                    info.flag_minus = '-';
                }
                if (format[i] == ' ') {
                    info.flags = ' ';
                }
                if (format[i] == '+') {
                    info.flags = '+';
                }
                if (format[i] == 'l')
                    info.len = 'l';
                if (format[i] == 'h')
                    info.len = 'h';
                if (format[i] == 'c') {
                    len += format_c(str, a, info, len);
                    flag = 1;
                }
                if (format[i] == 'd' || format[i] == 'i') {
                    len += format_d(&str[len], a, info);
                    flag = 1;
                }
                if (format[i] == 's') {
                    len += format_s(&str[len], a, info);
                    flag = 1;
                }
                if (format[i] == '%') {
                    str[len] = '%';
                    len++;
                    flag = 1;
                }
                if (format[i] == 'u') {
                    len += format_u(&str[len], a, info);
                    flag = 1;
                }
                if (format[i] == 'f') {
                    len += format_f(&str[len], a, info) + 1;
                    flag = 1;
                }
                if (format[i])
                    i++;
                }
            } else {
            str[len] = format[i];
            len++;
            i++;
            }
    }
    str[len] = '\0';
    return len;
}

int s21_sprintf(char *str, const char *format, ...) {
    t_spec info;
    va_list a;
    va_start(a, format);
    int ret = 0;
    structnull(&info);
    ret = parsing(str, format, info, &a);
    va_end(a);
    return ret;
}

int s21_isdigit(char c) { return (c >= '0' && c <= '9'); }
