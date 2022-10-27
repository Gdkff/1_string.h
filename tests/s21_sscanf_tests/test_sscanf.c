#include "../../s21_sscanf/s21_sscanf.h"
#include <check.h>
#include <math.h>

START_TEST(test_sscanf) {
    char str[] = "straponee 123.456e2siemens";
    double a1, a2;
    int i1, i2;
    int c;
    c = s21_sscanf(str, "straponee%lf", &a1);
    sscanf(str, "straponee%lf", &a2);
    ck_assert(fabs(a1 - a2) < 1e-10);
    ck_assert_int_eq(c, 1);

    char chr1 = 0;
    char chr2 = 0;
    a1 = 0;
    a2 = 0;
    c = s21_sscanf(str, "stra     %c    poneeeeeeeee%lf", &chr1, &a1);
    sscanf(str, "stra     %c    poneeeeeeeee%lf", &chr2, &a2);
    ck_assert_int_eq(chr1, chr2);
    ck_assert_int_eq(c, 1);
    ck_assert_int_eq(a1, a2);

    i1 = 0;
    i2 = 0;
    c = s21_sscanf("0123abc", "%i", &i1);
    sscanf("0123abc", "%i", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(c, 1);

    i1 = 0;
    i2 = 0;
    c = s21_sscanf("0x123abc", "%i", &i1);
    sscanf("0x123abc", "%i", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(c, 1);

    i1 = 0;
    i2 = 0;
    c = s21_sscanf("123abc", "%i", &i1);
    sscanf("123abc", "%i", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(c, 1);

    i1 = 0;
    i2 = 0;
    c = s21_sscanf("0123abc", "%o", &i1);
    sscanf("0123abc", "%o", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(c, 1);

    char s1[128], s2[128];
    c = s21_sscanf("jir\t\n da 123 i tolko", "j%s", s1);
    sscanf("jir\t\n da 123 i tolko", "j%s", s2);
    ck_assert_str_eq(s1, s2);
    ck_assert_int_eq(c, 1);

    unsigned int ui1, ui2;
    ui1 = 0;
    ui2 = 0;
    c = s21_sscanf("  %-0123", "%%%u", &ui1);
    sscanf("  %-0123", "%%%u", &ui2);
    ck_assert_int_eq(ui1, ui2);
    ck_assert_int_eq(c, 1);

    ui1 = 0;
    ui2 = 0;
    c = s21_sscanf("      0123", "%u", &ui1);
    sscanf("  0123", "%u", &ui2);
    ck_assert_int_eq(ui1, ui2);
    ck_assert_int_eq(c, 1);

    i1 = 0;
    i2 = 0;
    c = s21_sscanf("0Xabc1g, sovuh", "%x", &i1);
    sscanf("0Xabc1g, sovuh", "%x", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(c, 1);

    i1 = 0;
    i2 = 0;
    c = s21_sscanf("jaba abc1g, sovuh", "jaba   a%x", &i1);
    sscanf("jaba abc1g, sovuh", "jaba   a%x", &i2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(c, 1);

    long *p1, *p2;
    c = s21_sscanf("acbafo,dmmwwfmkl'dm", "%p", &p1);
    sscanf("acbafo,dmmwwfmkl'dm", "%p", &p2);
    ck_assert_int_eq((long)p1, (long)p2);
    ck_assert_int_eq(c, 1);

    p1 = S21_NULL;
    p2 = S21_NULL;
    i1 = 0;
    i2 = 0;
    c = s21_sscanf("acbafo,dmmwwfmkl'dm", "%p %n", &p1, &i1);
    sscanf("acbafo,dmmwwfmkl'dm", "%p %n", &p2, &i2);
    ck_assert_int_eq((long)p1, (long)p2);
    ck_assert_int_eq(i1, i2);
    ck_assert_int_eq(c, 2);
}
END_TEST
