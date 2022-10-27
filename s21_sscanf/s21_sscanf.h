#ifndef SRC_S21_SSCANF_S21_SSCANF_H_
#define SRC_S21_SSCANF_S21_SSCANF_H_

typedef unsigned long s21_size_t;
typedef struct s_params {
    int ignore;
    int error;
    s21_size_t width;
    s21_size_t size;
    char spec;
} params;

/**
 * @brief Функция возвращает 1, если в str есть символ,
 * отсутствующий в filter, иначе 0
 *
 * @param str
 * @param filter
 * @return int
 */
int s21_strpbrk_inv(const char *str, const char *filter);

/**
 * @brief Функция возвращает кол-во символов с начала строки
 * str, входящих в filter
 *
 * @param str
 * @param filter
 * @return int
 */
int s21_strcspn_inv(const char *str, const char *filter);
int count_spaces(const char *str);
char *get_token(char *dest, const char *str);
char *get_formatter(char *dest, const char *str);
void parse_formatter(params *p, const char *str);
void assign_uint(const char *str, char size, void *addr, char **end, int base);
void assign_double(const char *str, char size, void *addr, char **end);
int assign_value(const char *str, s21_size_t n, char spec, char size, void *addr, const char *origin);
int s21_sscanf(const char *str, const char *format, ...);

// s21_strto.c
int is_digit(int c);
int is_alpha(int c);
int is_upper(int c);
int s21_atoi(const char *str);
long s21_strtol(const char *str, char **end, int base);
unsigned long s21_strtoul(const char *str, char **end, int base);
double s21_strtod(const char *str, char **end);
long double s21_strtold(const char *str, char **end);

#endif  // SRC_S21_SSCANF_S21_SSCANF_H_
