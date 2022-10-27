#include "../s21_string.h"
#include <check.h>

START_TEST(test_strcat) {
    char buffer1[16];
    char buffer2[16];
    void *b1;
    void *b2;

    strcpy(buffer1, "jaba");
    strcpy(buffer2, "jaba");
    b1 = s21_strcat(buffer1, " solomid");
    b2 = strcat(buffer2, " solomid");
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);

    strcpy(buffer1, "jaba");
    strcpy(buffer2, "jaba");
    b1 = s21_strcat(buffer1, "\nsolomid");
    b2 = strcat(buffer2, "\nsolomid");
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);

    strcpy(buffer1, "");
    strcpy(buffer2, "");
    b1 = s21_strcat(buffer1, "\n");
    b2 = strcat(buffer2, "\n");
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);

    strcpy(buffer1, "");
    strcpy(buffer2, "");
    b1 = s21_strcat(buffer1, "");
    b2 = strcat(buffer2, "");
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
