#include "../../s21_sscanf/s21_sscanf.h"
#include <check.h>

START_TEST(test_count_spaces) {
    ck_assert_int_eq(count_spaces(""), 0);
    ck_assert_int_eq(count_spaces("   "), 3);
    ck_assert_int_eq(count_spaces("   \n\n"), 3);
    ck_assert_int_eq(count_spaces("j abik"), 0);
    ck_assert_int_eq(count_spaces("\t\t"), 0);
}
END_TEST
