#include "../s21_string.h"
#include <check.h>

START_TEST(test_strcpy) {
    char buffer1[16];
    char buffer2[16];
    void *b1;
    void *b2;

    memset(buffer1, '\0', 16);
    memset(buffer2, '\0', 16);
    b1 = s21_strcpy(buffer1, "pavlin");
    b2 = strcpy(buffer2, "pavlin");
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);

    memset(buffer1, '\0', 16);
    memset(buffer2, '\0', 16);
    b1 = s21_strcpy(buffer1, "");
    b2 = strcpy(buffer2, "");
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);

    memset(buffer1, '\0', 16);
    memset(buffer2, '\0', 16);
    b1 = s21_strcpy(buffer1, "\n ");
    b2 = strcpy(buffer2, "\n ");
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
