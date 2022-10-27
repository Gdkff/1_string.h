#include "../../s21_sscanf/s21_sscanf.h"
#include <check.h>
#include <math.h>

START_TEST(test_strtod) {
    double d;
    double e;
    char *p;
    d = s21_strtod("    123.456pavel", &p);
    e = strtod("    123.456pavel", NULL);
    ck_assert(fabs(d - e) < 1e-6);
    ck_assert_int_eq(*p, 'p');

    d = s21_strtod("123zo", NULL);
    e = strtod("123zo", NULL);
    ck_assert(fabs(d - e) < 1e-6);

    d = s21_strtod("", &p);
    e = strtod("", NULL);
    ck_assert(fabs(d - e) < 1e-6);
    ck_assert_int_eq(*p, '\0');

    d = s21_strtod("+e+2", NULL);
    e = strtod("+e+2", NULL);
    ck_assert(fabs(d - e) < 1e-6);

    d = s21_strtod("-e-2", NULL);
    e = strtod("-e-2", NULL);
    ck_assert(fabs(d - e) < 1e-6);

    d = s21_strtod("123.456e-4", NULL);
    e = strtod("123.456e-4", NULL);
    ck_assert(fabs(d - e) < 1e-6);

    d = s21_strtod("-4e+2ab", &p);
    e = strtod("-4e+2ab", NULL);
    ck_assert(fabs(d - e) < 1e-6);
    ck_assert_int_eq(*p, 'a');
}
END_TEST
