#include "../s21_string.h"
#include <check.h>

START_TEST(test_strncmp) {
    ck_assert_int_ge(s21_strncmp("Hello", "Hello", 10) * strncmp("Hello", "Hello", 10), 0);
    ck_assert_int_ge(s21_strncmp("Hello world", "A", 3) * strncmp("Hello world", "A", 3), 0);
    ck_assert_int_ge(s21_strncmp("Hello world", "Z", 2) * strncmp("Hello world", "Z", 2), 0);
    ck_assert_int_ge(s21_strncmp("Hello world", "\0", 0) * strncmp("Hello world", "\0", 0), 0);
    ck_assert_int_ge(s21_strncmp("Hello world", "\0", 20) * strncmp("Hello world", "\0", 20), 0);
    ck_assert_int_ge(s21_strncmp("a\n\0", "\0", 3) * strncmp("a\n\0", "\0", 3), 0);
    ck_assert_int_ge(s21_strncmp("a\n\0", "\n", 3) * strncmp("a\n\0", "\n", 3), 0);
    ck_assert_int_ge(s21_strncmp(" \0", "\0", 2) * strncmp(" \0", "\0", 2), 0);
    ck_assert_int_ge(s21_strncmp(" \0", " ", 2) * strncmp(" \0", " ", 2), 0);
    ck_assert_int_ge(s21_strncmp(" ", " ", 15) * strncmp(" ", " ", 15), 0);
    ck_assert_int_ge(s21_strncmp("\0", " ", 1) * strncmp("\0", " ", 1), 0);
    ck_assert_int_ge(s21_strncmp("\0", "\0", 1) * strncmp("\0", "\0", 1), 0);
    ck_assert_int_ge(s21_strncmp("\0", "\n", 1) * strncmp("\0", "\n", 1), 0);

    ck_assert_int_ge(s21_strncmp(" \0", " ", 20) * strncmp(" \0", " ", 20), 0);
    ck_assert_int_ge(s21_strncmp(" ", " ", 20) * strncmp(" ", " ", 20), 0);
    ck_assert_int_ge(s21_strncmp("\0", " ", 20) * strncmp("\0", " ", 20), 0);
    ck_assert_int_ge(s21_strncmp("\0", "\0", 20) * strncmp("\0", "\0", 20), 0);
    ck_assert_int_ge(s21_strncmp("\0", "\n", 20) * strncmp("\0", "\n", 20), 0);
}
END_TEST
