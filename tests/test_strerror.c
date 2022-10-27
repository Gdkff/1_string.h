#include "../s21_string.h"
#include <check.h>

START_TEST(test_strerror) {
    char *str1 = s21_strerror(20);
    char *str2 = strerror(20);
    ck_assert_str_eq(str1, str2);

    char *str3 = s21_strerror(12);
    char *str4 = strerror(12);
    ck_assert_str_eq(str3, str4);

    char *str5 = s21_strerror(1337);
    char *str6 = strerror(1337);
    ck_assert_str_eq(str5, str6);

    char *str7 = s21_strerror(1);
    char *str8 = strerror(1);
    ck_assert_str_eq(str7, str8);

    char *str9 = s21_strerror(25);
    char *str10 = strerror(25);
    ck_assert_str_eq(str9, str10);

    char *str11 = s21_strerror(134);
    char *str12 = strerror(134);
    ck_assert_str_eq(str11, str12);
}
END_TEST
