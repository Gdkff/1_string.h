#include "../s21_string.h"
#include <stdarg.h>
#include <stdlib.h>

int s21_strpbrk_inv(const char *str, const char *filter) {
    int res = 0;
    int flag;
    for (char *p1 = (char*)str; *p1 != '\0'; p1++) {
        flag = 0;
        for (char *p2 = (char*)filter; *p2 != '\0'; p2++) {
            if (*p1 == *p2) {
                flag = 1;
            }
        }
        // флаг будет равен 0, если в str есть символ, которого нет в filter
        if (flag == 0) {
            res = 1;
            break;
        }
    }
    return res;
}

int s21_strcspn_inv(const char *str, const char *filter) {
    int res = 0;
    int flag;
    for (char *p1 = (char*)str; *p1 != '\0'; p1++) {
        flag = 0;
        for (char *p2 = (char*)filter; *p2 != '\0'; p2++) {
            if (*p1 == *p2) flag = 1;
        }
        if (flag) {
            res++;
        } else {
            break;
        }
    }
    return res;
}

int count_spaces(const char *str) {
    int res = 0;

    for (char *p = (char*)str; *p == ' '; p++) {
        res++;
    }

    return res;
}

char *get_token(char *dest, const char *str) {
    int n = s21_strlen(str);
    char *temp_str = malloc(sizeof(*temp_str) * (n+1));
    if (temp_str == S21_NULL) {
        return S21_NULL;
    }

    char *end = &*(char*)str;
    s21_strcpy(temp_str, str);

    int spaces = 0;
    if (*temp_str == ' ') {
        spaces = count_spaces(temp_str);
    }

    char *res = S21_NULL;
    if (*(temp_str+spaces) != '%') {
        s21_strtok(temp_str+spaces, " \t\n%");
        int shift = s21_strlen(temp_str);

        s21_strcpy(dest, temp_str + spaces);
        res = end + shift;
    }
    free(temp_str);
    return res;
}

char *get_formatter(char *dest, const char *str) {
    const char specs[] = "cdieEfgGosuxXpn%";
    char *start = S21_NULL;
    char *end = S21_NULL;

    if (str != S21_NULL) {
        start = s21_strchr(str, '%');
    }
    if (start != S21_NULL && s21_strpbrk(start+1, specs)) {
        // поиск первого вхождения спецификатора
        end = start + s21_strcspn(start+1, specs) + 2;
        if (dest != S21_NULL) {
            s21_memcpy(dest, start, end - start);
            dest[end-str] = '\0';
        }
    }
    return end;
}
// atoi, strtol, strtoul, strtod, strtold
void parse_formatter(params *p, const char *str) {
    char accept[] = "cdieEfgGosuxXpn%hlL0123456789*";
    if (str != S21_NULL && !s21_strpbrk_inv(str, accept)) {
        if (s21_strchr(str, '*') != S21_NULL) {
            // printf("\ndebug %d\n", strchr(str, '*') != S21_NULL);
            p->ignore = 1;
            // printf("ignore = %d\n", p->ignore);
        } else {
            s21_size_t len = s21_strlen(str);

            p->spec = str[len-1];

            // если предпоследний символ в hlL , то это размер переменной
            char *tmp = s21_strpbrk(str+len-2, "hlL");
            if (tmp != S21_NULL) {
                p->size = str[len-2];

                // если hlL где-то не на предпоследнем символе - ошибка
                if (tmp != s21_strchr(str, p->size)) {
                    p->error = 1;
                }
            }
            p->width = 0;
            if (s21_strpbrk(str, "123456789") != S21_NULL) {
                p->width = s21_atoi(str+1);
            }
        }
    } else {
        p->error = 1;
    }
}

void assign_int(const char *str, char size, void *addr, char **end, int base) {
    if (size == 'h') *(short*)addr = (short)s21_strtol(str, end, base);
    else if (size == 'l') *(long*)addr = s21_strtol(str, end, base);
    else
        *(int*)addr = (int)s21_strtol(str, end, base);
}

void assign_uint(const char *str, char size, void *addr, char **end, int base) {
    if (size == 'h') *(unsigned short*)addr = (unsigned short)s21_strtol(str, end, base);
    else if (size == 'l') *(unsigned long*)addr = s21_strtoul(str, end, base);
    else
        *(unsigned int*)addr = (unsigned int)s21_strtol(str, end, base);
}

void assign_double(const char *str, char size, void *addr, char **end) {
    if (size == 'L') *(long double*)addr = s21_strtold(str, end);
    else
        *(double*)addr = s21_strtod(str, end);
}

int assign_value(const char *str, s21_size_t n, char spec, char size, void *addr, const char *origin) {
    if (addr == S21_NULL) {
        return 0;
    }
    int assigned = 0;
    char *end;

    int spaces = count_spaces(str);
    // str += spaces;
    // n += spaces;
    // printf("\n\ndbug =%s'", str);

    int len = s21_strlen(str) + 1;
    char *temp_str = malloc(sizeof(*temp_str) * len);
    if (temp_str == S21_NULL) {
        return 0;
    }
    s21_strncpy(temp_str, str, n);

    int n_flag = 0;
    char *p = temp_str + spaces;
    switch (spec) {
        case 'c':
            *(char*)addr = *temp_str;
            assigned = 1;
            break;
        case 'd':
            assign_int(p, size, addr, &end, 10);
            break;
        case 'i':
            if (p != S21_NULL && *(p) == '0') {
                if (p+1 != S21_NULL && (*(p+1) == 'x' || *(p+1) == 'X')) {
                    // *(int*)addr = (int)strtol(temp_str, &end, 16);
                    assign_int(p, size, addr, &end, 16);
                } else {
                    // *(int*)addr = (int)strtol(temp_str, &end, 8);
                    assign_int(p, size, addr, &end, 8);
                }
            } else {
                // *(int*)addr = (int)strtol(temp_str, &end, 10);
                assign_int(p, size, addr, &end, 10);
            }
            break;
        case 'e':
        case 'E':
        case 'f':
        case 'g':
        case 'G':
            assign_double(p, size, addr, &end);
            break;
        case 'o':
            assign_uint(p, size, addr, &end, 8);
            break;
        case 's':
            s21_strcpy(addr, s21_strtok(p, " \t\n"));
            assigned = s21_strlen(p);
            break;
        case 'u':
            assign_uint(p, size, addr, &end, 10);
            break;
        case 'x':
        case 'X':
            assign_uint(p, size, addr, &end, 16);
            break;
        case 'p':
            *(long*)addr = s21_strtol(p, &end, 16);
            break;
        case 'n':
            *(int*)addr = (int)(str - origin);
            n_flag = 1;
            break;
    }

    if (assigned == 0 && n_flag == 0) {
        assigned = end - temp_str;
    }

    free(temp_str);
    return assigned;
}

int s21_sscanf(const char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);

    char formatter[128] = {0};
    char token1[128] = {0};
    char token2[128] = {0};
    params p = {0};
    int count_assign = 0;
    void *val = S21_NULL;
    // void *prev_val = S21_NULL;
    // int flag_val = 0;

    // указатель на текущий символ в format
    char *curr = (char*) format;
    // указатель на текущий символ в str
    char *pstr = (char*) str;

    while (1) {
        s21_memset(&p, 0, sizeof(p));
        if (curr == S21_NULL || *curr == 0) break;
        if (*curr == '%') {
            curr = get_formatter(formatter, curr);
            if (curr == S21_NULL) break;
            parse_formatter(&p, formatter);
            if (p.error == 1) break;
            if (p.ignore == 1) continue;

            if (p.spec == '%') {
                pstr += count_spaces(pstr);
                if (*pstr == '%') {
                    pstr += 1;
                    continue;
                } else {
                    break;
                }
            }
            if (p.width == 0) p.width = s21_strlen(pstr);

            // if (flag_val == 1) {
            //     prev_val = val;
            // }

            val = va_arg(args, void*);
            // long diff;
            // if (flag_val == 1) {
            //     diff = prev_val - val;
            //     // если расстояние между адрессами слишком большое - скорее всего это не наш аргумент
            //     if (diff < -256 || diff > 256) break;  // костыль жесткий
            // } else {
            //     flag_val = 1;
            // }
            // // pstr += count_spaces(pstr);
            // printf("\n\ndebug ='%s' '%s'\n\n", pstr, str);
            int shift = assign_value(pstr, p.width, p.spec, p.size, val, str);
            count_assign++;
            pstr += shift;
        } else {
            char *tmp_curr;
            tmp_curr = get_token(token1, curr);
            if (tmp_curr == S21_NULL) {
                curr += s21_strcspn(curr, "%");
                continue;
            } else {
                curr = tmp_curr;
            }

            get_token(token2, pstr);

            if (!s21_strncmp(token1, token2, s21_strlen(token1))) {
                pstr += count_spaces(pstr);
                pstr += s21_strlen(token1);
            } else {
                break;
            }
        }
    }
    va_end(args);
    return count_assign;
}
