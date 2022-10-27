#include "../../s21_sscanf/s21_sscanf.h"
#include <check.h>

START_TEST(test_get_formatter) {
    char formatter[128] = {0};
    char *p;
    p = get_formatter(formatter, "%1d%2d");
    ck_assert_str_eq(formatter, "%1d");
    ck_assert_int_eq(*p, '%');

    p = get_formatter(formatter, " slonik pa\travozniy   %1ld    %2d");
    ck_assert_str_eq(formatter, "%1ld");
    ck_assert_int_eq(*p, ' ');

    p = get_formatter(formatter, "%b b b b bLGbabushka");
    ck_assert_str_eq(formatter, "%b b b b bLG");
    ck_assert_int_eq(*p, 'b');

    p = get_formatter(formatter, "");
    ck_assert_ptr_eq(p, S21_NULL);

    p = get_formatter(formatter, S21_NULL);
    ck_assert_ptr_eq(p, S21_NULL);
}
END_TEST
