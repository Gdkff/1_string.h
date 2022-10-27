#include "../s21_string.h"
#include <check.h>
#include <string.h>

START_TEST(test_memcmp) {
    ck_assert_int_ge(s21_memcmp("Hello", "Hello", 6) * memcmp("Hello", "Hello", 6), 0);
    ck_assert_int_ge(s21_memcmp("Hello world", "A", 2) * memcmp("Hello world", "A", 2), 0);
    ck_assert_int_ge(s21_memcmp("Hello world", "Z", 2) * memcmp("Hello world", "Z", 2), 0);
    ck_assert_int_ge(s21_memcmp("Hello world", "\0", 0) * memcmp("Hello world", "\0", 0), 0);
    ck_assert_int_ge(s21_memcmp("Hello world", "\0", 2) * memcmp("Hello world", "\0", 2), 0);
    ck_assert_int_ge(s21_memcmp("a\n\0", "\0", 2) * memcmp("a\n\0", "\0", 2), 0);
    ck_assert_int_ge(s21_memcmp("a\n\0", "\n", 2) * memcmp("a\n\0", "\n", 2), 0);
    ck_assert_int_ge(s21_memcmp(" \0", "\0", 2) * memcmp(" \0", "\0", 2), 0);
    ck_assert_int_ge(s21_memcmp(" \0", " ", 2) * memcmp(" \0", " ", 2), 0);
    ck_assert_int_ge(s21_memcmp(" ", " ", 2) * memcmp(" ", " ", 2), 0);
    ck_assert_int_ge(s21_memcmp("\0", " ", 1) * memcmp("\0", " ", 1), 0);
    ck_assert_int_ge(s21_memcmp("\0", "\0", 1) * memcmp("\0", "\0", 1), 0);
    ck_assert_int_ge(s21_memcmp("\0", "\n", 1) * memcmp("\0", "\n", 1), 0);
}
END_TEST
