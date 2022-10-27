#include "../s21_string.h"
#include <check.h>
#include <string.h>
START_TEST(test_strcspn) {
    ck_assert_int_eq(s21_strcspn("0123456789", "6789"), strcspn("0123456789", "6789"));
    ck_assert_int_eq(s21_strcspn("0123456789", "9876"), strcspn("0123456789", "9876"));
    ck_assert_int_eq(s21_strcspn("0123456789", "\n"), strcspn("0123456789", "\n"));
    ck_assert_int_eq(s21_strcspn("0123456789", "545454"), strcspn("0123456789", "545454"));
    ck_assert_int_eq(s21_strcspn("0123456789", "hel\n0"), strcspn("0123456789", "hel\n0"));
    ck_assert_int_eq(s21_strcspn("0123456789", ""), strcspn("0123456789", ""));
    ck_assert_int_eq(s21_strcspn("", "123"), strcspn("", "123"));
    ck_assert_int_eq(s21_strcspn("", ""), strcspn("", ""));
    ck_assert_int_eq(s21_strcspn(" \n\n", " "), strcspn(" \n\n", " "));
}
END_TEST
