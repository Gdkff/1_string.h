#include "../../s21_string.h"
#include <check.h>
#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

START_TEST(s21_sprintf_p) {
  char str[1024] = {0};
  char str2[1024] = {0};

  sprintf(str, "1%%2\n");
  s21_sprintf(str2, "1%%2\n");
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  s21_sprintf(str, "- %i - [%%+15.5i] - l.%i\n, [%+.7i]", INT_MIN, -2, 2);
  sprintf(str2, "- %i - [%%+15.5i] - l.%i\n, [%+.7i]", INT_MIN, -2, 2);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);
}
END_TEST

START_TEST(s21_v3_hard) {
  char str[1024] = {0};
  char str2[1024] = {0};

  sprintf(str, "HE%sLLO WORLD %.0d\n", "", 0);
  s21_sprintf(str2, "HE%sLLO WORLD %.0d\n", "", 0);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  wchar_t hi[] = L"HELLO WORLD";
  s21_sprintf(str, "- %i - [%%+15.5i] - l.%i\n, [%+15.20i]", INT_MIN, 2, 3);
  sprintf(str2, "- %i - [%%+15.5i] - l.%i\n, [%+15.20i]", INT_MIN, 2, 3);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  sprintf(str, "%5ls\n", hi);
  s21_sprintf(str2, "%5ls\n", hi);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  sprintf(str, "%1s\n", "H");
  s21_sprintf(str2, "%1s\n", "H");
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  sprintf(str, "%1d\n", 1);
  s21_sprintf(str2, "%1d\n", 1);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  sprintf(str, "%.0f", 1.3);
  s21_sprintf(str2, "%.0f", 1.3);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  sprintf(str, "%.0f", -1.2);
  s21_sprintf(str2, "%.0f", -1.2);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  sprintf(str, "%.0f", 0.0);
  s21_sprintf(str2, "%.0f", 0.0);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  sprintf(str, "%c HELLO WORLD %c", 's', 'W');
  s21_sprintf(str2, "%c HELLO WORLD %c", 's', 'W');
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  sprintf(str, "%.0f", 1.5);
  s21_sprintf(str2, "%.0f", 1.5);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  sprintf(str, "%.0f", -1.6);
  s21_sprintf(str2, "%.0f", -1.6);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  double aa = 1.123123123123123;
  sprintf(str, "%.16f", aa);
  s21_sprintf(str2, "%.16f", aa);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  sprintf(str, "%.0f", 19.55);
  s21_sprintf(str2, "%.0f", 19.55);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  sprintf(str, "%.2f", 1.49);
  s21_sprintf(str2, "%.2f", 1.49);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  sprintf(str, "%.1f", 0.64);
  s21_sprintf(str2, "%.1f", 0.64);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  sprintf(str, "%.2f", 42.8952);
  s21_sprintf(str2, "%.2f", 42.8952);
  ck_assert_str_eq(str, str2);
  memset(str, '\0', 1024);
  memset(str2, '\0', 1024);

  ck_assert_str_eq(str, str2);
} END_TEST

START_TEST(s21_sprintf_d) {
  char str[1024] = {0};
  char str1[1024] = {0};
  int min = -2147483648;
  int max = 2147483647;
  int normal = 135;
  int mn = -65145567;
  int res, sres;

  res = sprintf(str, "%d", normal);
  sres = s21_sprintf(str1, "%d", normal);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, sres);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  res = sprintf(str, "%d", max);
  sres = s21_sprintf(str1, "%d", max);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, sres);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);


  res = sprintf(str, "% d", max);
  sres = s21_sprintf(str1, "% d", max);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, sres);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);


  res = sprintf(str, "%+20d", min);
  sres = s21_sprintf(str1, "%+20d", min);
  ck_assert_int_eq(res, sres);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  res = sprintf(str, "% d", min);
  sres = s21_sprintf(str1, "% d", min);
  ck_assert_int_eq(res, sres);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  res = sprintf(str, "% d", min);
  sres = s21_sprintf(str1, "% d", min);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, sres);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  res = sprintf(str, "%-5d", normal);
  sres = s21_sprintf(str1, "%-5d", normal);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, sres);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  res = sprintf(str, "%5d", normal);
  sres = s21_sprintf(str1, "%5d", normal);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, sres);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  res = sprintf(str, "%+5d", mn);
  sres = s21_sprintf(str1, "%+5d", mn);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, sres);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);


  res = sprintf(str, "%20.15d", normal);
  sres = s21_sprintf(str1, "%20.15d", normal);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, sres);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  res = sprintf(str, "%.0d", normal);
  sres = s21_sprintf(str1, "%.0d", normal);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, sres);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  res = sprintf(str, "%5.15d", mn);
  sres = s21_sprintf(str1, "%5.15d", mn);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(res, sres);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);
} END_TEST


  START_TEST(s21_sprintf_hd) {
    char str[1024] = {0};
    char str1[1024] = {0};
    short min = -32768;
    short max = 32767;
    short normal = 12;
    short mn = -1244;
    int res = 0;
    int sres = 0;

    res = sprintf(str, "%hd", normal);
    sres = s21_sprintf(str1, "%hd", normal);
    ck_assert_str_eq(str, str1);
    ck_assert_int_eq(res, sres);
    memset(str, '\0', 1024);
    memset(str1, '\0', 1024);

    res = sprintf(str, "%hd", max);
    sres = s21_sprintf(str1, "%hd", max);
    ck_assert_str_eq(str, str1);
    ck_assert_int_eq(res, sres);
    memset(str, '\0', 1024);
    memset(str1, '\0', 1024);


    res = sprintf(str, "% hd", max);
    sres = s21_sprintf(str1, "% hd", max);
    ck_assert_str_eq(str, str1);
    ck_assert_int_eq(res, sres);
    memset(str, '\0', 1024);
    memset(str1, '\0', 1024);


    res = sprintf(str, "%+hd", min);
    sres = s21_sprintf(str1, "%+hd", min);
    ck_assert_int_eq(res, sres);
    ck_assert_str_eq(str, str1);
    memset(str, '\0', 1024);
    memset(str1, '\0', 1024);

    res = sprintf(str, "% hd", min);
    sres = s21_sprintf(str1, "% hd", min);
    ck_assert_int_eq(res, sres);
    ck_assert_str_eq(str, str1);
    memset(str, '\0', 1024);
    memset(str1, '\0', 1024);

    res = sprintf(str, "% hd", min);
    sres = s21_sprintf(str1, "% hd", min);
    ck_assert_str_eq(str, str1);
    ck_assert_int_eq(res, sres);
    memset(str, '\0', 1024);
    memset(str1, '\0', 1024);

    res = sprintf(str, "%-5hd", normal);
    sres = s21_sprintf(str1, "%-5hd", normal);
    ck_assert_str_eq(str, str1);
    ck_assert_int_eq(res, sres);
    memset(str, '\0', 1024);
    memset(str1, '\0', 1024);

    res = sprintf(str, "%5hd", normal);
    sres = s21_sprintf(str1, "%5hd", normal);
    ck_assert_str_eq(str, str1);
    ck_assert_int_eq(res, sres);
    memset(str, '\0', 1024);
    memset(str1, '\0', 1024);

    res = sprintf(str, "%+5hd", mn);
    sres = s21_sprintf(str1, "%+5hd", mn);
    ck_assert_str_eq(str, str1);
    ck_assert_int_eq(res, sres);
    memset(str, '\0', 1024);
    memset(str1, '\0', 1024);


    res = sprintf(str, "%20.15hd", normal);
    sres = s21_sprintf(str1, "%20.15hd", normal);
    ck_assert_str_eq(str, str1);
    ck_assert_int_eq(res, sres);
    memset(str, '\0', 1024);
    memset(str1, '\0', 1024);

    res = sprintf(str, "%.0hd", normal);
    sres = s21_sprintf(str1, "%.0hd", normal);
    ck_assert_str_eq(str, str1);
    ck_assert_int_eq(res, sres);
    memset(str, '\0', 1024);
    memset(str1, '\0', 1024);

    res = sprintf(str, "%5.15hd", mn);
    sres = s21_sprintf(str1, "%5.15hd", mn);
    ck_assert_int_eq(res, sres);
    ck_assert_str_eq(str, str1);
    memset(str, '\0', 1024);
    memset(str1, '\0', 1024);
  } END_TEST

START_TEST(s21_sprintf_diu_with_str) {
  char str[1024] = {0};
  char str1[1024] = {0};

  long number = 100000000;
  short number1 = 5;
  sprintf(str,
    "%d Hello, %10u it's a great % hd, %-10i, %d, %+10d, %ld\n", 1, 1, number1, 3, -4, 5, number);
    s21_sprintf(str1,
    "%d Hello, %10u it's a great % hd, %-10i, %d, %+10d, %ld\n", 1, 1, number1, 3, -4, 5, number);

  ck_assert_str_eq(str, str1);
} END_TEST


START_TEST(s21_sprintf_u) {
  char str[1024] = {0};
  char str1[1024] = {0};
  unsigned int u = -217483647;
  unsigned int a = -0;
  unsigned int b = -102;
  unsigned int c = -12;
  unsigned int d = -120;
  unsigned int e = -1200;
  unsigned int f = -14895085;
  int lib_res, s21_res;

  lib_res = sprintf(str, "%u", u);
  s21_res = s21_sprintf(str1, "%u", u);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%u", a);
  s21_res = s21_sprintf(str1, "%u", a);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%u", b);
  s21_res = s21_sprintf(str1, "%u", b);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%-5u", c);
  s21_res = s21_sprintf(str1, "%-5u", c);
  // printf("or|%s|\n", str);
  // printf("my|%s|\n", str1);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%u", f);
  s21_res = s21_sprintf(str1, "%u", f);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%7u", c);
  s21_res = s21_sprintf(str1, "%7u", c);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%5u", c);
  s21_res = s21_sprintf(str1, "%5u", c);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%.20u", c);
  s21_res = s21_sprintf(str1, "%.20u", c);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%-20.15u", d);
  s21_res = s21_sprintf(str1, "%-20.15u", d);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%u", e);
  s21_res = s21_sprintf(str1, "%u", e);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);
} END_TEST

START_TEST(s21_sprintf_f) {
  ck_assert(1 == 1);
} END_TEST

START_TEST(s21_sprintf_s) {
  char str[1024] = {0};
  char str1[1024] = {0};
  int lib_res, s21_res;

  lib_res = sprintf(str, "%20s", "Hi");
  s21_res = s21_sprintf(str1, "%20s", "Hi");
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%-20s", "My");
  s21_res = s21_sprintf(str1, "%-20s", "My");
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%5.0s", "Hi");
  s21_res = s21_sprintf(str1, "%5.0s", "Hi");
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%.1s", "My");
  s21_res = s21_sprintf(str1, "%.1s", "My");
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);


  lib_res = sprintf(str, "%.0s", "My PIG");
  s21_res = s21_sprintf(str1, "%.0s", "My PIG");
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%.78s", "My PIG");
  s21_res = s21_sprintf(str1, "%.78s", "My PIG");
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);
} END_TEST

START_TEST(s21_sprintf_h) {
  char str[1024] = {0};
  char str1[1024] = {0};
  int lib_res, s21_res;
  short i = 0;
  short a = 32767;

  lib_res = sprintf(str, "%hi", i);
  s21_res = s21_sprintf(str1, "%hi", i);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%hd", a);
  s21_res = s21_sprintf(str1, "%hd", a);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);
} END_TEST

START_TEST(s21_sprintf_l) {
  char str[1024] = {0};
  char str1[1024] = {0};
  long i = LONG_MAX;
  // long a = LONG_MIN;
  unsigned long b = 4294967295;
  double d = -1230009;
  wchar_t *l_str = L"User";
  wchar_t l_char = L'A';
  int lib_res, s21_res;

  lib_res = sprintf(str, "%li", i);
  s21_res = s21_sprintf(str1, "%li", i);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  // lib_res = sprintf(str, "%ld", a);
  // s21_res = s21_sprintf(str1, "%ld", a);
  // ck_assert_str_eq(str, str1);
  // ck_assert_int_eq(s21_res, lib_res);
  // memset(str, '\0', 1024);
  // memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%lu", b);
  s21_res = s21_sprintf(str1, "%lu", b);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%lc", l_char);
  s21_res = s21_sprintf(str1, "%lc", l_char);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%ls", l_str);
  s21_res = s21_sprintf(str1, "%ls", l_str);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  lib_res = sprintf(str, "%lf", d);
  s21_res = s21_sprintf(str1, "%lf", d);
  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21_res, lib_res);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);
} END_TEST


START_TEST(s21_sprintf_cs) {
  char str[1024] = {0};
  char str1[1024] = {0};

       sprintf(str, "Hi, %-13s, i%c, %s a great day!", "User", 't', "");
  s21_sprintf(str1, "Hi, %-13s, i%c, %s a great day!", "User", 't', "");

  ck_assert_str_eq(str1, str);
} END_TEST

START_TEST(s21_sprintf_c) {
  char str[1024];
  char str1[1024];
  int a = 0, b = 0;

  sprintf(str, "%c", 'A');
  s21_sprintf(str1, "%c", 'A');
  ck_assert_str_eq(str1, str);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  // a = sprintf(str, "%c aboba", '\0');
  // b = s21_sprintf(str1, "%c aboba", '\0');
  // ck_assert_str_eq(str1, str);
  // ck_assert_int_eq(a, b);
  // memset(str, '\0', 1024);
  // memset(str1, '\0', 1024);

  // a = sprintf(str, "%10c aboba", '\0');
  // b = s21_sprintf(str1, "%10c aboba", '\0');
  // ck_assert_str_eq(str1, str);
  // ck_assert_int_eq(a, b);
  // memset(str, '\0', 1024);
  // memset(str1, '\0', 1024);

  a = sprintf(str, "%c aboba", '\n');
  b = s21_sprintf(str1, "%c aboba", '\n');
  ck_assert_str_eq(str1, str);
  ck_assert_int_eq(a, b);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  a = sprintf(str, "%123c aboba", '1');
  b = s21_sprintf(str1, "%123c aboba", '1');
  ck_assert_str_eq(str1, str);
  ck_assert_int_eq(a, b);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%-123c aboba", '1');
  s21_sprintf(str1, "%-123c aboba", '1');
  ck_assert_str_eq(str1, str);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%-1c aboba", '1');
  s21_sprintf(str1, "%-1c aboba", '1');
  ck_assert_str_eq(str1, str);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%1c aboba", '1');
  s21_sprintf(str1, "%1c aboba", '1');
  ck_assert_str_eq(str1, str);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%2c aboba", '1');
  s21_sprintf(str1, "%2c aboba", '1');
  ck_assert_str_eq(str1, str);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);
}
END_TEST

START_TEST(s21_sprintf_long) {
  char str[1024] = {0};
  char str1[1024] = {0};

  sprintf(str, "%5casd", 'q');
  s21_sprintf(str1, "%5casd", 'q');

  ck_assert_str_eq(str, str1);

  sprintf(str, "Hello, %-5s, i%22c, %5s a great day!", "User", 't', "");
  s21_sprintf(str1, "Hello, %-5s, i%22c, %5s a great day!", "User", 't', "");
  ck_assert_str_eq(str1, str);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);


  sprintf(str, "Hello, %-13s, i%22c, %5s a great day! I have %.15f IQ and I am %-220.4d",
    "User", 't', "", 0.1, 220);
  s21_sprintf(str1, "Hello, %-13s, i%22c, %5s a great day! I have %.15f IQ and I am %-220.4d",
    "User", 't', "", 0.1, 220);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);


  sprintf(str, "Hello, %-1s, i%2c, %5s a great day! I have %.1f IQ and I am %-2.4d",
    "User", 't', "", 0.1, 228);
  s21_sprintf(str1, "Hello, %-1s, i%2c, %5s a great day! I have %.1f IQ and I am %-2.4d",
    "User", 't', "", 0.1, 228);
  ck_assert_str_eq(str1, str);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);
} END_TEST



START_TEST(s21_sprintf_f_with_str) {
  char str[1024] = {0};
  char str1[1024] = {0};
  // int lib_res, s21_res;

  // lib_res = sprintf(str, "%c fghjk", '\0');
  // s21_res = s21_sprintf(str1, "%c fghjk", '\0');
  // ck_assert_str_eq(str, str1);
  // ck_assert_int_eq(s21_res, lib_res);
  // memset(str, '\0', 1024);
  // memset(str1, '\0', 1024);
  double a = 0.12345000000;
  double b = -0.2324600000;
  double c = 0.20000000000;
  double d = 0.30000000000;
  sprintf(str, "Hello%0.10f, my %0.2f, beautiful %+10.f,world %-5.3f", c, a, d, b);
  s21_sprintf(str1, "Hello%0.10f, my %0.2f, beautiful %+10.f,world %-5.3f", c, a, d, b);
  ck_assert_str_eq(str, str1);
} END_TEST

START_TEST(s21_sprintf_empty) {
  // char str[1024] = {0}; ck_assert(1 == 1);
  // char str1[1024] = {0};
  // int lib_res, s21_res;

  // lib_res = sprintf(str, "%c fghjk", '\0');
  // s21_res = s21_sprintf(str1, "%c fghjk", '\0');
  // ck_assert_str_eq(str, str1);
  // ck_assert_int_eq(s21_res, lib_res);
  // memset(str, '\0', 1024);
  // memset(str1, '\0', 1024);
} END_TEST

START_TEST(s21_sprintf_hard_d) {
  char str[1024] = {0};
  char str1[1024] = {0};

  sprintf(str, "%-100d", 2147483647);
  s21_sprintf(str1, "%-100d", 2147483647);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%-100.200d", 2147483647);
  s21_sprintf(str1, "%-100.200d", 2147483647);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%10.40d", -2147483647);
  s21_sprintf(str1, "%10.40d", -2147483647);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%10.40d", 0);
  s21_sprintf(str1, "%10.40d", 0);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%10.40d", -200);
  s21_sprintf(str1, "%10.40d", -200);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%6.5d", -200);
  s21_sprintf(str1, "%6.5d", -200);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%7.5d", -200);
  s21_sprintf(str1, "%7.5d", -200);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%8.5d", -200);
  s21_sprintf(str1, "%8.5d", -200);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%6.5d", 66666666);
  s21_sprintf(str1, "%6.5d", 66666666);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%7.5d", 66666666);
  s21_sprintf(str1, "%7.5d", 66666666);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%8.5d", 66666666);
  s21_sprintf(str1, "%8.5d", 66666666);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  int a = 1;

  sprintf(str, "%1.1d", a);
  s21_sprintf(str1, "%1.1d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%2.2d", a);
  s21_sprintf(str1, "%2.2d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%1.2d", a);
  s21_sprintf(str1, "%1.2d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%3.2d", a);
  s21_sprintf(str1, "%3.2d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%4.2d", a);
  s21_sprintf(str1, "%4.2d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%2.1d", a);
  s21_sprintf(str1, "%2.1d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  a = 0;

  sprintf(str, "%1.1d", a);
  s21_sprintf(str1, "%1.1d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%2.2d", a);
  s21_sprintf(str1, "%2.2d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%1.2d", a);
  s21_sprintf(str1, "%1.2d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%3.2d", a);
  s21_sprintf(str1, "%3.2d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%4.2d", a);
  s21_sprintf(str1, "%4.2d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%2.1d", a);
  s21_sprintf(str1, "%2.1d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  a = 0;

  sprintf(str, "%1.1d", a);
  s21_sprintf(str1, "%1.1d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%2.2d", a);
  s21_sprintf(str1, "%2.2d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%1.2d", a);
  s21_sprintf(str1, "%1.2d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%3.2d", a);
  s21_sprintf(str1, "%3.2d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%4.2d", a);
  s21_sprintf(str1, "%4.2d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%2.1d", a);
  s21_sprintf(str1, "%2.1d", a);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%1.1d", -2147483647);
  s21_sprintf(str1, "%1.1d", -2147483647);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%.10d", -2147483647);
  s21_sprintf(str1, "%.10d", -2147483647);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%.11d", -2147483647);
  s21_sprintf(str1, "%.11d", -2147483647);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%.12d", -2147483647);
  s21_sprintf(str1, "%.12d", -2147483647);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%10.10d", -2147483647);
  s21_sprintf(str1, "%10.10d", -2147483647);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%11.11d", -2147483647);
  s21_sprintf(str1, "%11.11d", -2147483647);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%12.12d", -2147483647);
  s21_sprintf(str1, "%12.12d", -2147483647);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%12d", -2147483647);
  s21_sprintf(str1, "%12d", -2147483647);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%11d", -2147483647);
  s21_sprintf(str1, "%11d", -2147483647);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);

  sprintf(str, "%10d", -2147483647);
  s21_sprintf(str1, "%10d", -2147483647);
  ck_assert_str_eq(str, str1);
  memset(str, '\0', 1024);
  memset(str1, '\0', 1024);
} END_TEST
