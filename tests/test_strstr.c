#include "../s21_string.h"
#include <check.h>

START_TEST(test_strstr) {
    char str[128];

    strcpy(str, "Hello");
    ck_assert_ptr_eq(s21_strstr(str, "Hello"), strstr(str, "Hello"));

    strcpy(str, "Hello world");
    ck_assert_ptr_eq(s21_strstr(str, "A"), strstr(str, "A"));

    strcpy(str, "Hello world");
    ck_assert_ptr_eq(s21_strstr(str, "Z"), strstr(str, "Z"));

    strcpy(str, "Hello world");
    ck_assert_ptr_eq(s21_strstr(str, "\0"), strstr(str, "\0"));

    strcpy(str, "Hello world");
    ck_assert_ptr_eq(s21_strstr(str, "\0"), strstr(str, "\0"));

    strcpy(str, "a\n\0");
    ck_assert_ptr_eq(s21_strstr(str, "\0"), strstr(str, "\0"));

    strcpy(str, "a\n\0");
    ck_assert_ptr_eq(s21_strstr(str, "\n"), strstr(str, "\n"));

    strcpy(str, " \0");
    ck_assert_ptr_eq(s21_strstr(str, "\0"), strstr(str, "\0"));

    strcpy(str, " \0");
    ck_assert_ptr_eq(s21_strstr(str, " "), strstr(str, " "));

    strcpy(str, " ");
    ck_assert_ptr_eq(s21_strstr(str, " "), strstr(str, " "));

    strcpy(str, "\0");
    ck_assert_ptr_eq(s21_strstr(str, " "), strstr(str, " "));

    strcpy(str, "\0");
    ck_assert_ptr_eq(s21_strstr(str, "\0"), strstr(str, "\0"));

    strcpy(str, "\0");
    ck_assert_ptr_eq(s21_strstr(str, "\n"), strstr(str, "\n"));
}
END_TEST
