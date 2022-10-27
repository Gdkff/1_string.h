#include "../s21_string.h"
#include <check.h>

START_TEST(test_strlen) {
    ck_assert_int_eq(s21_strlen("Hello world"), strlen("Hello world"));
    ck_assert_int_eq(s21_strlen("Hello world\n"), strlen("Hello world\n"));
    ck_assert_int_eq(s21_strlen("a\n"), strlen("a\n"));
    ck_assert_int_eq(s21_strlen(" \n"), strlen(" \n"));
    ck_assert_int_eq(s21_strlen(" "), strlen(" "));
    ck_assert_int_eq(s21_strlen("\n"), strlen("\n"));
    ck_assert_int_eq(s21_strlen(""), strlen(""));
}
END_TEST
