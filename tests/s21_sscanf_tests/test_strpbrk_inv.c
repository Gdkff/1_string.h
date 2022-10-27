#include "../../s21_sscanf/s21_sscanf.h"
#include <check.h>

START_TEST(test_strpbrk_inv) {
    ck_assert_int_eq(s21_strpbrk_inv("jaba", "baj"), 0);
    ck_assert_int_eq(s21_strpbrk_inv("abbb", "ba"), 0);
    ck_assert_int_eq(s21_strpbrk_inv("abbb", "sobak"), 0);
    ck_assert_int_eq(s21_strpbrk_inv("abbb", "akula"), 1);
    ck_assert_int_eq(s21_strpbrk_inv("abbb", "slonic"), 1);
    ck_assert_int_eq(s21_strpbrk_inv("abbb", ""), 1);
    ck_assert_int_eq(s21_strpbrk_inv("", "abcd"), 0);
    ck_assert_int_eq(s21_strpbrk_inv(" \n", "\n"), 1);
    ck_assert_int_eq(s21_strpbrk_inv("  \n", "\n "), 0);
}
END_TEST
