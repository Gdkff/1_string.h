#include "../s21_string.h"
#include <check.h>

START_TEST(test_strchr) {
    ck_assert_ptr_eq(s21_strchr("Hello world", 'w'), strchr("Hello world", 'w'));
    ck_assert_ptr_eq(s21_strchr("Hello world", ' '), strchr("Hello world", ' '));
    ck_assert_ptr_eq(s21_strchr("Hello world", ' '), strchr("Hello world", ' '));
    ck_assert_ptr_eq(s21_strchr("Hello world", 'H'), strchr("Hello world", 'H'));
    ck_assert_ptr_eq(s21_strchr("Hello world", '\0'), strchr("Hello world", '\0'));
    ck_assert_ptr_eq(s21_strchr("Hello world", '\0'), strchr("Hello world", '\0'));
    ck_assert_ptr_eq(s21_strchr("a\n\0", '\0'), strchr("a\n\0", '\0'));
    ck_assert_ptr_eq(s21_strchr("a\n\0", '\n'), strchr("a\n\0", '\n'));
    ck_assert_ptr_eq(s21_strchr(" \0", '\0'), strchr(" \0", '\0'));
    ck_assert_ptr_eq(s21_strchr(" \0", ' '), strchr(" \0", ' '));
    ck_assert_ptr_eq(s21_strchr(" \0", 'w'), strchr(" \0", 'w'));
    ck_assert_ptr_eq(s21_strchr("\0", ' '), strchr("\0", ' '));
    ck_assert_ptr_eq(s21_strchr("\0", '\0'), strchr("\0", '\0'));
    ck_assert_ptr_eq(s21_strchr("\0", '\n'), strchr("\0", '\n'));
}
END_TEST
