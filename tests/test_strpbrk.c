#include "../s21_string.h"
#include <check.h>

START_TEST(test_strpbrk) {
    char *str1 = "hello";
    char *str2 = "hel";
    char *res1, *res2;
    res1 = s21_strpbrk(str1, str2);
    res2 = strpbrk(str1, str2);
    ck_assert_str_eq(res1, res2);

    char *str4 = "ab";
    res1 = s21_strpbrk(str1, str4);
    res2 = strpbrk(str1, str4);
    ck_assert_ptr_eq(res1, res2);

    char *str5 = "o";
    res1 = s21_strpbrk(str1, str5);
    res2 = strpbrk(str1, str5);
    ck_assert_str_eq(res1, res2);

    char *str6 = "abcdefghjkl";
    char *str7 = "abcd";
    res1 = s21_strpbrk(str6, str7);
    res2 = strpbrk(str6, str7);
    ck_assert_str_eq(res1, res2);

    char *str8 = "aboba is shrek?";
    char *str9 = "is";
    res1 = s21_strpbrk(str8, str9);
    res2 = s21_strpbrk(str8, str9);
    ck_assert_str_eq(res1, res2);
}
END_TEST
