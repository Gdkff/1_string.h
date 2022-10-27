#include "../../s21_sscanf/s21_sscanf.h"
#include <check.h>

START_TEST(test_strtold) {
    long double d;
    long double e;
    char *p;
    d = s21_strtold("    123.456pavel", &p);
    e = strtold("    123.456pavel", S21_NULL);
    ck_assert(fabsl(d - e) < 1e-6);
    ck_assert_int_eq(*p, 'p');

    d = s21_strtold("123zo", S21_NULL);
    e = strtold("123zo", S21_NULL);
    ck_assert(fabsl(d - e) < 1e-6);

    d = s21_strtold("", &p);
    e = strtold("", S21_NULL);
    ck_assert(fabsl(d - e) < 1e-6);
    ck_assert_int_eq(*p, '\0');

    d = s21_strtold("+e+2", S21_NULL);
    e = strtold("+e+2", S21_NULL);
    ck_assert(fabsl(d - e) < 1e-6);

    d = s21_strtold("-e-2", S21_NULL);
    e = strtold("-e-2", S21_NULL);
    ck_assert(fabsl(d - e) < 1e-6);

    d = s21_strtold("123.456e-4", S21_NULL);
    e = strtold("123.456e-4", S21_NULL);
    ck_assert(fabsl(d - e) < 1e-6);

    d = s21_strtold("-4e+2ab", &p);
    e = strtold("-4e+2ab", S21_NULL);
    ck_assert(fabsl(d - e) < 1e-6);
    ck_assert_int_eq(*p, 'a');
}
END_TEST
