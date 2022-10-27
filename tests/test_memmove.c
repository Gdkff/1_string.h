#include "../s21_string.h"
#include <check.h>

START_TEST(test_memmove) {
    char buffer1[10];
    char buffer2[10];
    void *b1;
    void *b2;

    memcpy(buffer1, "123456789", 10);
    memcpy(buffer2, "123456789", 10);
    b1 = s21_memmove(&buffer1[4], &buffer1[3], 3);
    b2 = memmove(&buffer2[4], &buffer2[3], 3);
    ck_assert_ptr_eq(b1, &buffer1[4]);
    ck_assert_ptr_eq(b2, &buffer2[4]);
    ck_assert_str_eq(buffer1, buffer2);

    memcpy(buffer1, "123456789", 10);
    memcpy(buffer2, "123456789", 10);
    b1 = s21_memmove(&buffer1[3], &buffer1[4], 3);
    b2 = memmove(&buffer2[3], &buffer2[4], 3);
    ck_assert_ptr_eq(b1, &buffer1[3]);
    ck_assert_ptr_eq(b2, &buffer2[3]);
    ck_assert_str_eq(buffer1, buffer2);

    memcpy(buffer1, "", 1);
    memcpy(buffer2, "", 1);
    b1 = s21_memmove(&buffer1[0], &buffer1[0], 1);
    b2 = memmove(&buffer2[0], &buffer2[0], 1);
    ck_assert_ptr_eq(b1, &buffer1[0]);
    ck_assert_ptr_eq(b2, &buffer2[0]);
    ck_assert_str_eq(buffer1, buffer2);

    memcpy(buffer1, "\n23", 4);
    memcpy(buffer2, "\n23", 4);
    b1 = s21_memmove(&buffer1[1], &buffer1[0], 2);
    b2 = memmove(&buffer2[1], &buffer2[0], 2);
    ck_assert_ptr_eq(b1, &buffer1[1]);
    ck_assert_ptr_eq(b2, &buffer2[1]);
    ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
