#include "../s21_string.h"
#include <check.h>

START_TEST(test_strcmp) {
    ck_assert_int_ge(s21_strcmp("Hello", "Hello") * strcmp("Hello", "Hello"), 0);
    ck_assert_int_ge(s21_strcmp("Hello world", "A") * strcmp("Hello world", "A"), 0);
    ck_assert_int_ge(s21_strcmp("Hello world", "Z") * strcmp("Hello world", "Z"), 0);
    ck_assert_int_ge(s21_strcmp("Hello world", "\0") * strcmp("Hello world", "\0"), 0);
    ck_assert_int_ge(s21_strcmp("Hello world", "\0") * strcmp("Hello world", "\0"), 0);
    ck_assert_int_ge(s21_strcmp("a\n\0", "\0") * strcmp("a\n\0", "\0"), 0);
    ck_assert_int_ge(s21_strcmp("a\n\0", "\n") * strcmp("a\n\0", "\n"), 0);
    ck_assert_int_ge(s21_strcmp(" \0", "\0") * strcmp(" \0", "\0"), 0);
    ck_assert_int_ge(s21_strcmp(" \0", " ") * strcmp(" \0", " "), 0);
    ck_assert_int_ge(s21_strcmp(" ", " ") * strcmp(" ", " "), 0);
    ck_assert_int_ge(s21_strcmp("\0", " ") * strcmp("\0", " "), 0);
    ck_assert_int_ge(s21_strcmp("\0", "\0") * strcmp("\0", "\0"), 0);
    ck_assert_int_ge(s21_strcmp("\0", "\n") * strcmp("\0", "\n"), 0);
}
END_TEST
