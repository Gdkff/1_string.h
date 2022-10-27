#include "../../s21_sscanf/s21_sscanf.h"
#include <check.h>

START_TEST(test_atoi) {
    ck_assert_int_eq(s21_atoi("123"), 123);
    ck_assert_int_eq(s21_atoi("-123"), -123);
    ck_assert_int_eq(s21_atoi("       +000123"), 123);
    ck_assert_int_eq(s21_atoi("+     000123"), 0);
    ck_assert_int_eq(s21_atoi("-000123"), -123);
    ck_assert_int_eq(s21_atoi(""), 0);
    ck_assert_int_eq(s21_atoi("-"), 0);
    ck_assert_int_eq(s21_atoi("123jaba4"), 123);
    ck_assert_int_eq(s21_atoi("a123"), 0);
    ck_assert_int_eq(s21_atoi("123.45"), 123);
    ck_assert_int_eq(s21_atoi("123-45"), 123);
    ck_assert_int_eq(s21_atoi("00000"), 0);
    ck_assert_int_eq(s21_atoi("0a0a0a"), 0);
    ck_assert_int_eq(s21_atoi(NULL), 0);
}
END_TEST
