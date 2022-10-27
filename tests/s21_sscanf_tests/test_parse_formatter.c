#include "../../s21_sscanf/s21_sscanf.h"
#include <check.h>

START_TEST(test_parse_formatter) {
    params p = {0};
    parse_formatter(&p, "%d");
    ck_assert_int_eq(p.spec, 'd');

    parse_formatter(&p, "%32LG");
    ck_assert_int_eq(p.ignore, 0);
    ck_assert_int_eq(p.spec, 'G');
    ck_assert_int_eq(p.size, 'L');
    ck_assert_int_eq(p.width, 32);

    parse_formatter(&p, "%3*2LG");
    ck_assert_int_eq(p.ignore, 1);

    parse_formatter(&p, "slonik))");
    ck_assert_int_eq(p.error, 1);
}
END_TEST
