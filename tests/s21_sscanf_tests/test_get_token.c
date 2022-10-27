#include "../../s21_sscanf/s21_sscanf.h"
#include <check.h>

START_TEST(test_get_token) {
    char token[128] = {0};
    char *p;
    p = get_token(token, "   aboba sus  ");
    ck_assert_str_eq(token, "aboba");
    ck_assert_int_eq(p[-1], 'a');
    ck_assert_int_eq(p[1], 's');

    p = get_token(token, "");
    ck_assert_int_eq(*p, '\0');

    p = get_token(token, "aboba%hellsus");
    ck_assert_str_eq(token, "aboba");
    ck_assert_int_eq(*p, '%');

    p = get_token(token, "     %sammich gnida");
    // ck_assert_str_eq(token);
    ck_assert_ptr_eq(p, S21_NULL);
}
END_TEST
