#include "../../s21_sscanf/s21_sscanf.h"
#include <check.h>
#include <math.h>

START_TEST(test_strtoul) {
    char *p;
    ck_assert_int_eq(s21_strtoul("-123", &p, 10), strtoul("-123", NULL, 10));
    ck_assert_int_eq(*p, '\0');

    ck_assert_int_eq(s21_strtoul("-\t123", &p, 10), strtoul("-\t123", NULL, 10));
    ck_assert_int_eq(*p, '\t');

    // ck_assert_int_eq(s21_strtoul("-123", &p, -1), strtoul("-123", NULL, -1));
    // ck_assert_int_eq(*p, '1');

    ck_assert_int_eq(s21_strtoul("   +0123a", &p, 10), strtoul("   +0123a", NULL, 10));
    ck_assert_int_eq(*p, 'a');

    ck_assert_int_eq(s21_strtoul("0123a", &p, 8), strtoul("0123a", NULL, 8));
    ck_assert_int_eq(*p, 'a');

    ck_assert_int_eq(s21_strtoul("0123a", &p, 8), strtoul("0123a", NULL, 8));
    ck_assert_int_eq(*p, 'a');

    ck_assert_int_eq(s21_strtoul("0123a", &p, 16), strtoul("0123a", NULL, 16));
    ck_assert_int_eq(*p, '\0');

    ck_assert_int_eq(s21_strtoul("0Z123a", &p, 16), strtoul("0Z123a", NULL, 16));
    ck_assert_int_eq(*p, 'Z');

    ck_assert_int_eq(s21_strtoul("0X123a", &p, 16), strtoul("0X123a", NULL, 16));
    ck_assert_int_eq(*p, '\0');

    ck_assert_int_eq(s21_strtoul("0X1", &p, 8), strtoul("0X1", NULL, 8));
    ck_assert_int_eq(*p, 'X');

    ck_assert_int_eq(s21_strtoul("", &p, 20), strtoul("", NULL, 20));
    ck_assert_int_eq(*p, '\0');

    ck_assert_int_eq(s21_strtoul("1xa1", &p, 16), strtoul("1xa1", NULL, 16));
    ck_assert_int_eq(*p, 'x');

    ck_assert_int_eq(s21_strtoul("   123 jabbik", &p, 17), strtoul("   123 jabbik", NULL, 17));
    ck_assert_int_eq(*p, ' ');
}
END_TEST
