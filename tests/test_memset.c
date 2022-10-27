#include "../s21_string.h"
#include <check.h>

START_TEST(test_memset) {
    char buffer1[10];
    char buffer2[10];
    void *b1;
    void *b2;

    memcpy(buffer1, "123456789", 10);
    memcpy(buffer2, "123456789", 10);
    for (int i = 0; i < 10; i+=2) {
        b1 = s21_memset(buffer1, '0', 1);
        b2 = memset(buffer2, '0', 1);
    }
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);

    memcpy(buffer1, "123456789", 10);
    memcpy(buffer2, "123456789", 10);
    for (int i = 0; i < 10; i+=2) {
        b1 = s21_memset(buffer1, '0', 4);
        b2 = memset(buffer2, '0', 4);
    }
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);

    memcpy(buffer1, "123456789", 10);
    memcpy(buffer2, "123456789", 10);
    b1 = s21_memset(buffer1, '\n', 9);
    b2 = memset(buffer2, '\n', 9);
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);

    memcpy(buffer1, "123456789", 10);
    memcpy(buffer2, "123456789", 10);
    b1 = s21_memset(buffer1, '\0', 9);
    b2 = memset(buffer2, '\0', 9);
    ck_assert_ptr_eq(b1, buffer1);
    ck_assert_ptr_eq(b2, buffer2);
    ck_assert_str_eq(buffer1, buffer2);
    for (int i = 0; i < 10; i++) {
        ck_assert_int_eq(buffer1[i], buffer2[i]);
    }
}
END_TEST
