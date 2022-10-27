#include "../../s21_sscanf/s21_sscanf.h"
#include <check.h>

START_TEST(test_strcspn_inv) {
    ck_assert_int_eq(s21_strcspn_inv("abbb", "ba"), 4);
    ck_assert_int_eq(s21_strcspn_inv("abbb", "sobak"), 4);
    ck_assert_int_eq(s21_strcspn_inv("abbb", "akula"), 1);
    ck_assert_int_eq(s21_strcspn_inv("abbb", "slonic"), 0);
    ck_assert_int_eq(s21_strcspn_inv("abbb", ""), 0);
    ck_assert_int_eq(s21_strcspn_inv("", "abcd"), 0);
    ck_assert_int_eq(s21_strcspn_inv(" \n", "\n"), 0);
    ck_assert_int_eq(s21_strcspn_inv("  \n", "\n "), 3);
}
END_TEST
