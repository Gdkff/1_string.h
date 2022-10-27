#include "../s21_string.h"
#include <check.h>
#include <string.h>

START_TEST(test_memchr) {
    ck_assert_ptr_eq(s21_memchr("Hello world", 'w', 6), memchr("Hello world", 'w', 6));
    ck_assert_ptr_eq(s21_memchr("Hello world", ' ', 6), memchr("Hello world", ' ', 6));
    ck_assert_ptr_eq(s21_memchr("Hello world", ' ', 0), memchr("Hello world", ' ', 0));
    ck_assert_ptr_eq(s21_memchr("Hello world", 'H', 0), memchr("Hello world", 'H', 0));
    ck_assert_ptr_eq(s21_memchr("Hello world", '\0', 0), memchr("Hello world", '\0', 0));
    ck_assert_ptr_eq(s21_memchr("Hello world", '\0', 20), memchr("Hello world", '\0', 20));
    ck_assert_ptr_eq(s21_memchr("a\n\0", '\0', 3), memchr("a\n\0", '\0', 3));
    ck_assert_ptr_eq(s21_memchr("a\n\0", '\n', 3), memchr("a\n\0", '\n', 3));
    ck_assert_ptr_eq(s21_memchr(" \0", '\0', 2), memchr(" \0", '\0', 2));
    ck_assert_ptr_eq(s21_memchr(" \0", ' ', 2), memchr(" \0", ' ', 2));
    ck_assert_ptr_eq(s21_memchr(" \0", 'w', 2), memchr(" \0", 'w', 2));
    ck_assert_ptr_eq(s21_memchr("\0", ' ', 1), memchr("\0", ' ', 1));
    ck_assert_ptr_eq(s21_memchr("\0", '\0', 1), memchr("\0", '\0', 1));
    ck_assert_ptr_eq(s21_memchr("\0", '\n', 1), memchr("\0", '\n', 1));
}
END_TEST
