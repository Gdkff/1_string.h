#include "../s21_string.h"
#include <check.h>

START_TEST(test_strrchr) {
    ck_assert_ptr_eq(s21_strrchr("Hello world", 'w'), strrchr("Hello world", 'w'));
    ck_assert_ptr_eq(s21_strrchr("Hello world", ' '), strrchr("Hello world", ' '));
    ck_assert_ptr_eq(s21_strrchr("Hello world", ' '), strrchr("Hello world", ' '));
    ck_assert_ptr_eq(s21_strrchr("Hello world", 'H'), strrchr("Hello world", 'H'));
    ck_assert_ptr_eq(s21_strrchr("Hello world", '\0'), strrchr("Hello world", '\0'));
    ck_assert_ptr_eq(s21_strrchr("Hello world", '\0'), strrchr("Hello world", '\0'));
    ck_assert_ptr_eq(s21_strrchr("a\n\0", '\0'), strrchr("a\n\0", '\0'));
    ck_assert_ptr_eq(s21_strrchr("a\n\0", '\n'), strrchr("a\n\0", '\n'));
    ck_assert_ptr_eq(s21_strrchr(" \0", '\0'), strrchr(" \0", '\0'));
    ck_assert_ptr_eq(s21_strrchr(" \0", ' '), strrchr(" \0", ' '));
    ck_assert_ptr_eq(s21_strrchr(" \0", 'w'), strrchr(" \0", 'w'));
    ck_assert_ptr_eq(s21_strrchr("\0", ' '), strrchr("\0", ' '));
    ck_assert_ptr_eq(s21_strrchr("\0", '\0'), strrchr("\0", '\0'));
    ck_assert_ptr_eq(s21_strrchr("\0", '\n'), strrchr("\0", '\n'));
}
END_TEST
