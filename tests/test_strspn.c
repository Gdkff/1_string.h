#include "../s21_string.h"
#include <check.h>

START_TEST(test_strspn) {
    ck_assert_int_eq(s21_strspn("0123456789", "210 "), strspn("0123456789", "210 "));
    ck_assert_int_eq(s21_strspn("\n", "\n"), strspn("\n", "\n"));
    ck_assert_int_eq(s21_strspn("\n", ""), strspn("\n", ""));
    ck_assert_int_eq(s21_strspn("", ""), strspn("", ""));
    ck_assert_int_eq(s21_strspn("a aa aaabbbbb", "a "), strspn("a aa aaabbbbb", "a "));
}
END_TEST
