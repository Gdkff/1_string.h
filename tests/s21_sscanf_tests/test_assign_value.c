#include "../../s21_sscanf/s21_sscanf.h"
#include <check.h>
#include <math.h>

START_TEST(test_assign_value) {
    int a = 0;
    long la = 0;
    short ha = 0;
    char str[] = "12 34 56";
    assign_value(str + 2, 4, 'd', 'z', &a, str);
    ck_assert_int_eq(a, 34);

    a = 0;
    assign_value(str + 2, 1, 'd', 0, &a, str);
    ck_assert_int_eq(a, 3);

    la = 0;
    assign_value(str + 2, 1, 'd', 'l', &la, str);
    ck_assert_int_eq(la, 3);

    ha = 0;
    assign_value(str + 2, 1, 'd', 'h', &ha, str);
    ck_assert_int_eq(ha, 3);

    double lf = 0;
    long double Lf = 0;
    char str1[] = "aba123.456";
    assign_value(str1+3, 666, 'f', 0, &lf, str1);
    ck_assert_msg(fabs(lf - 123.456) < 1e-6, "lf = '%lf', expected = '123.456'", lf);

    assign_value(str1+3, 4, 'e', 'l', &lf, str1);
    ck_assert_msg(fabs(lf - 123.4) < 1e-6, "lf = '%lf', expected = '123.4'", lf);

    assign_value(str1+2, 666, 'g', 0, &lf, str1);
    ck_assert_msg(fabs(lf - 0) < 1e-6, "lf = '%lf', expected = '0'", lf);

    assign_value(str1+3, 5, 'G', 'L', &Lf, str1);
    ck_assert_msg(fabsl(Lf - 123.45) < 1e-6, "Lf = '%Lf', expected = '123.45'", Lf);

    assign_value(str1+2, 666, 'f', 'L', &Lf, str1);
    ck_assert_msg(fabsl(Lf - 0) < 1e-6, "Lf = '%Lf', expected = '0'", Lf);
}
END_TEST
