#include "../s21_string.h"
#include <check.h>

START_TEST(test_strtok) {
    char str1[128];
    char str2[128];
    char *tok1;
    char *tok2;

    strcpy(str1, "1-2-3");
    strcpy(str2, "1-2-3");
    tok1 = s21_strtok(str1, "- ");
    tok2 = strtok(str2, "- ");
    ck_assert_str_eq(tok1, tok2);
    ck_assert_str_eq(str1, str2);
    tok1 = s21_strtok(NULL, "- ");
    tok2 = strtok(NULL, "- ");
    ck_assert_str_eq(tok1, tok2);
    ck_assert_str_eq(str1, str2);
    tok1 = s21_strtok(NULL, "- ");
    tok2 = strtok(NULL, "- ");
    ck_assert_str_eq(tok1, tok2);
    ck_assert_str_eq(str1, str2);
    tok1 = s21_strtok(NULL, "- ");
    tok2 = strtok(NULL, "- ");
    ck_assert_ptr_eq(tok1, tok2);
    ck_assert_ptr_eq(tok1, S21_NULL);

    strcpy(str1, "1-2-3");
    strcpy(str2, "1-2-3");
    tok1 = s21_strtok(str1, "");
    tok2 = strtok(str2, "");
    ck_assert_str_eq(tok1, tok2);
    ck_assert_str_eq(str1, str2);
    tok1 = s21_strtok(NULL, "");
    tok2 = strtok(NULL, "");
    ck_assert_ptr_eq(tok1, tok2);
    ck_assert_ptr_eq(tok1, S21_NULL);

    strcpy(str1, "");
    strcpy(str2, "");
    tok1 = s21_strtok(str1, "kjgjngjken");
    tok2 = strtok(str2, "kjgjngjken");
    ck_assert_str_eq(str1, str2);
    ck_assert_ptr_eq(tok1, tok2);
    ck_assert_ptr_eq(tok1, S21_NULL);
}
END_TEST
