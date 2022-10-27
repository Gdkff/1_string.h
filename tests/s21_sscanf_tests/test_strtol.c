#include "../../s21_sscanf/s21_sscanf.h"
#include <check.h>
#include <string.h>
#include <math.h>

START_TEST(test_strtol) {
    char *p;
    ck_assert_int_eq(s21_strtol("-123", &p, 10), strtol("-123", NULL, 10));
    ck_assert_int_eq(*p, '\0');

    ck_assert_int_eq(s21_strtol("-\t123", &p, 10), strtol("-\t123", NULL, 10));
    ck_assert_int_eq(*p, '\t');

    // ck_assert_int_eq(s21_strtol("-123", &p, -1), strtol("-123", NULL, -1));
    // ck_assert_int_eq(*p, '1');

    ck_assert_int_eq(s21_strtol("   +0123a", &p, 10), strtol("   +0123a", NULL, 10));
    ck_assert_int_eq(*p, 'a');

    ck_assert_int_eq(s21_strtol("0123a", &p, 8), strtol("0123a", NULL, 8));
    ck_assert_int_eq(*p, 'a');

    ck_assert_int_eq(s21_strtol("0123a", &p, 8), strtol("0123a", NULL, 8));
    ck_assert_int_eq(*p, 'a');

    ck_assert_int_eq(s21_strtol("0123a", &p, 16), strtol("0123a", NULL, 16));
    ck_assert_int_eq(*p, '\0');

    ck_assert_int_eq(s21_strtol("0Z123a", &p, 16), strtol("0Z123a", NULL, 16));
    ck_assert_int_eq(*p, 'Z');

    ck_assert_int_eq(s21_strtol("0X123a", &p, 16), strtol("0X123a", NULL, 16));
    ck_assert_int_eq(*p, '\0');

    ck_assert_int_eq(s21_strtol("0X1", &p, 8), strtol("0X1", NULL, 8));
    ck_assert_int_eq(*p, 'X');

    ck_assert_int_eq(s21_strtol("", &p, 20), strtol("", NULL, 20));
    ck_assert_int_eq(*p, '\0');

    ck_assert_int_eq(s21_strtol("1xa1", &p, 16), strtol("1xa1", NULL, 16));
    ck_assert_int_eq(*p, 'x');

    ck_assert_int_eq(s21_strtol("   123 jabbik", &p, 17), strtol("   123 jabbik", NULL, 17));
    ck_assert_int_eq(*p, ' ');
}
END_TEST
