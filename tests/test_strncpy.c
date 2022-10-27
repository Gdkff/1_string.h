#include "../s21_string.h"
#include <check.h>

START_TEST(test_strncpy) {
    char buffer1[16];
    char buffer2[16];
    void *b1;
    void *b2;

    memset(buffer1, '\0', 16);
    memset(buffer2, '\0', 16);
    b1 = s21_strncpy(buffer1, "pavlin", 7);
    b2 = strncpy(buffer2, "pavlin", 7);
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);

    memset(buffer1, '\0', 16);
    memset(buffer2, '\0', 16);
    b1 = s21_strncpy(buffer1, "", 1);
    b2 = strncpy(buffer2, "", 1);
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);

    memset(buffer1, '\0', 16);
    memset(buffer2, '\0', 16);
    b1 = s21_strncpy(buffer1, "\n", 2);
    b2 = strncpy(buffer2, "\n", 2);
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);

    memset(buffer1, '\0', 16);
    memset(buffer2, '\0', 16);
    b1 = s21_strncpy(buffer1, "\0\n", 3);
    b2 = strncpy(buffer2, "\0\n", 3);
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);

    // strncpy из стандартной string.h некорректно работает, если 3-й аргумент больше длины строки
    // memset(buffer1, '\0', 16);
    // memset(buffer2, '\0', 16);
    // b1 = s21_strncpy(buffer1, "pavlin", 20);
    // b2 = strncpy(buffer2, "pavlin", 20);
    // ck_assert_ptr_eq(b1, buffer1);
    // ck_assert_ptr_eq(b2, buffer2);
    // ck_assert_str_eq(buffer1, buffer2);

    // memset(buffer1, '\0', 16);
    // memset(buffer2, '\0', 16);
    // b1 = s21_strncpy(buffer1, "", 20);
    // b2 = strncpy(buffer2, "", 20);
    // ck_assert_ptr_eq(b1, buffer1);
    // ck_assert_ptr_eq(b2, buffer2);
    // ck_assert_str_eq(buffer1, buffer2);

    // memset(buffer1, '\0', 16);
    // memset(buffer2, '\0', 16);
    // b1 = s21_strncpy(buffer1, "\n", 20);
    // b2 = strncpy(buffer2, "\n", 20);
    // ck_assert_ptr_eq(b1, buffer1);
    // ck_assert_ptr_eq(b2, buffer2);
    // ck_assert_str_eq(buffer1, buffer2);

    // memset(buffer1, '\0', 16);
    // memset(buffer2, '\0', 16);
    // b1 = s21_strncpy(buffer1, "\0\n", 20);
    // b2 = strncpy(buffer2, "\0\n", 20);
    // ck_assert_ptr_eq(b1, buffer1);
    // ck_assert_ptr_eq(b2, buffer2);
    // ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
