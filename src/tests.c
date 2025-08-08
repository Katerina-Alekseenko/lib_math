#include <check.h>
#include <math.h>

#include "lib_math.h"

START_TEST(fmod_test) {
  ck_assert_ldouble_eq(lib_fmod(10.0, 2.0), fmod(10.0, 2.0));
  ck_assert_ldouble_eq(lib_fmod(10.0, LIB_INF), fmod(10.0, LIB_INF));
  ck_assert_ldouble_eq(lib_fmod(-3.0, -2.0), fmod(-3.0, -2.0));
  ck_assert_ldouble_nan(lib_fmod(LIB_INF, 89.0));
  ck_assert_ldouble_nan(fmod(LIB_INF, 89.0));
  ck_assert_ldouble_nan(lib_fmod(0.0, 0.0));
  ck_assert_ldouble_nan(fmod(0.0, 0.0));
}
END_TEST
START_TEST(abs_test) {
  ck_assert_int_eq(lib_abs(10), abs(10));
  ck_assert_int_eq(lib_abs(0), abs(0));
  ck_assert_int_eq(lib_abs(-1), abs(-1));
}
END_TEST
START_TEST(fabs_test) {
  ck_assert_ldouble_eq(lib_fabs(10.0), fabs(10.0));
  ck_assert_ldouble_eq(lib_fabs(0.0), fabs(0.0));
  ck_assert_ldouble_eq(lib_fabs(-1.0), fabs(-1.0));
}
END_TEST

START_TEST(cos_test) {
  ck_assert_ldouble_eq_tol(lib_cos(89999), cos(89999), E_6);
  ck_assert_ldouble_eq_tol(lib_cos(0.0000001), cos(0.0000001), E_6);
  ck_assert_ldouble_eq_tol(lib_cos(1.0000001), cos(1.0000001), E_6);
}
START_TEST(cos2_test) {
  ck_assert_ldouble_eq_tol(lib_cos(1), cos(1), E_6);
  ck_assert_ldouble_eq_tol(lib_cos(100), cos(100), E_6);
  ck_assert_ldouble_eq_tol(lib_cos(-1), cos(-1), E_6);
  ck_assert_ldouble_eq_tol(lib_cos(0), cos(0), E_6);
}
END_TEST
START_TEST(sin_test) {
  ck_assert_ldouble_eq_tol(lib_sin(89999), sin(89999), E_6);
  ck_assert_ldouble_eq_tol(lib_sin(0.0000001), sin(0.0000001), E_6);
  ck_assert_ldouble_eq_tol(lib_sin(1.0000001), sin(1.0000001), E_6);
}
START_TEST(sin2_test) {
  ck_assert_ldouble_eq_tol(lib_sin(1), sin(1), E_6);
  ck_assert_ldouble_eq_tol(lib_sin(100), sin(100), E_6);
  ck_assert_ldouble_eq_tol(lib_sin(-1), sin(-1), E_6);
  ck_assert_ldouble_eq_tol(lib_sin(0), sin(0), E_6);
  ck_assert_ldouble_nan(lib_sin(LIB_INF));
  ck_assert_ldouble_nan(sin(LIB_INF));
  ck_assert_ldouble_nan(lib_sin(LIB_INF));
  ck_assert_ldouble_nan(sin(LIB_MINUS_INF));
  ck_assert_ldouble_nan(lib_sin(LIB_MINUS_INF));
  ck_assert_ldouble_nan(sin(LIB_NAN));
  ck_assert_ldouble_nan(lib_sin(LIB_NAN));
}
END_TEST
START_TEST(tan_test) {
  ck_assert_ldouble_eq_tol(lib_tan(1), tan(1), E_6);
  ck_assert_ldouble_eq_tol(lib_tan(100), tan(100), E_6);
  ck_assert_ldouble_eq_tol(lib_tan(-1), tan(-1), E_6);
  ck_assert_ldouble_eq_tol(lib_tan(0), tan(0), E_6);
  ck_assert_ldouble_nan(lib_tan(LIB_INF));
  ck_assert_ldouble_nan(tan(LIB_INF));
  ck_assert_ldouble_nan(lib_tan(LIB_INF));
  ck_assert_ldouble_nan(tan(LIB_MINUS_INF));
  ck_assert_ldouble_nan(lib_tan(LIB_MINUS_INF));
  ck_assert_ldouble_nan(tan(LIB_NAN));
  ck_assert_ldouble_nan(lib_tan(LIB_NAN));
}
END_TEST
START_TEST(atan_test) {
  ck_assert_ldouble_eq_tol(lib_atan(0.999), atan(0.999), E_6);
  ck_assert_ldouble_eq_tol(lib_atan(0.099), atan(0.099), E_6);

  ck_assert_ldouble_eq_tol(lib_atan(100), atan(100), E_6);
  ck_assert_ldouble_eq_tol(lib_atan(55), atan(55), E_6);

  ck_assert_ldouble_eq_tol(lib_atan(-100), atan(-100), E_6);
  ck_assert_ldouble_eq_tol(lib_atan(-55), atan(-55), E_6);

  ck_assert_ldouble_eq_tol(lib_atan(-0.100), atan(-0.100), E_6);
  ck_assert_ldouble_eq_tol(lib_atan(-1), atan(-1), 0.00001);
  ck_assert_ldouble_eq_tol(lib_atan(LIB_INF), atan(LIB_INF), E_6);
  ck_assert_ldouble_eq_tol(lib_atan(LIB_MINUS_INF), atan(LIB_MINUS_INF), E_6);

  ck_assert_ldouble_nan(atan(LIB_NAN));
  ck_assert_ldouble_nan(lib_atan(LIB_NAN));
}
END_TEST
START_TEST(exp_test) {
  ck_assert_ldouble_eq_tol(lib_exp(0.999), exp(0.999), E_6);
  ck_assert_ldouble_eq_tol(lib_exp(0.099), exp(0.099), E_6);

  for (double i = -20.0; i < 20.0; i += 0.1) {
    ck_assert_ldouble_eq_tol(lib_exp(i), exp(i), E_6);
  }
}
START_TEST(sgrt_test) {
  ck_assert_ldouble_eq_tol(lib_sqrt(1), sqrt(1), E_6);
  ck_assert_ldouble_eq_tol(lib_sqrt(100), sqrt(100), E_6);
  ck_assert_ldouble_eq_tol(lib_sqrt(0.75), sqrt(0.75), E_6);
  ck_assert_ldouble_eq_tol(lib_sqrt(0), sqrt(0), E_6);
  ck_assert_ldouble_nan(lib_sqrt(-1));
  ck_assert_ldouble_nan(sqrt(-1));
  ck_assert_ldouble_infinite(lib_sqrt(LIB_INF));
  ck_assert_ldouble_infinite(sqrt(LIB_INF));
  ck_assert_ldouble_nan(sqrt(LIB_MINUS_INF));
  ck_assert_ldouble_nan(lib_sqrt(LIB_MINUS_INF));
  ck_assert_ldouble_nan(sqrt(LIB_NAN));
  ck_assert_ldouble_nan(lib_sqrt(LIB_NAN));
}
START_TEST(arsin_test) {
  ck_assert_ldouble_eq_tol(lib_asin(1), asin(1), E_6);
  ck_assert_ldouble_eq_tol(lib_asin(-1), asin(-1), E_6);
  ck_assert_ldouble_eq_tol(lib_asin(0.5), asin(0.5), E_6);
  ck_assert_ldouble_eq_tol(lib_asin(-0.5), asin(-0.5), E_6);
  ck_assert_ldouble_eq_tol(lib_asin(0), asin(0), E_6);

  ck_assert_ldouble_eq_tol(lib_asin(-1), asin(-1), E_6);
  ck_assert_ldouble_nan(asin(LIB_MINUS_INF));
  ck_assert_ldouble_nan(lib_asin(LIB_MINUS_INF));
  ck_assert_ldouble_nan(asin(LIB_INF));
  ck_assert_ldouble_nan(lib_asin(LIB_INF));
  ck_assert_ldouble_nan(asin(LIB_NAN));
  ck_assert_ldouble_nan(lib_asin(LIB_NAN));
  ck_assert_ldouble_nan(asin(10));
  ck_assert_ldouble_nan(lib_asin(10));
  ck_assert_ldouble_nan(asin(-10));
  ck_assert_ldouble_nan(lib_asin(-10));
}
START_TEST(arcos_test) {
  ck_assert_ldouble_eq_tol(lib_acos(1), acos(1), E_6);
  ck_assert_ldouble_eq_tol(lib_acos(-1), acos(-1), E_6);
  ck_assert_ldouble_eq_tol(lib_acos(0.5), acos(0.5), E_6);
  ck_assert_ldouble_eq_tol(lib_acos(-0.5), acos(-0.5), E_6);
  ck_assert_ldouble_eq_tol(lib_acos(0), acos(0), E_6);

  ck_assert_ldouble_eq_tol(lib_acos(-1), acos(-1), E_6);
  ck_assert_ldouble_nan(acos(LIB_MINUS_INF));
  ck_assert_ldouble_nan(lib_acos(LIB_MINUS_INF));
  ck_assert_ldouble_nan(acos(LIB_INF));
  ck_assert_ldouble_nan(lib_acos(LIB_INF));
  ck_assert_ldouble_nan(acos(LIB_NAN));
  ck_assert_ldouble_nan(lib_acos(LIB_NAN));
  ck_assert_ldouble_nan(acos(10));
  ck_assert_ldouble_nan(lib_acos(10));
  ck_assert_ldouble_nan(acos(-10));
  ck_assert_ldouble_nan(lib_acos(-10));
}
START_TEST(ceil_test) {
  ck_assert_ldouble_eq_tol(lib_ceil(0.1), ceil(0.1), E_6);
  ck_assert_ldouble_eq_tol(lib_ceil(1.0), ceil(1.0), E_6);
  ck_assert_ldouble_eq_tol(lib_ceil(0.170), ceil(0.170), E_6);
  ck_assert_ldouble_eq_tol(lib_ceil(-0.1), ceil(-0.1), E_6);
  ck_assert_ldouble_eq_tol(lib_ceil(0), ceil(0), E_6);
  ck_assert_ldouble_infinite(lib_ceil(LIB_INF));
  ck_assert_ldouble_infinite(ceil(LIB_INF));

  ck_assert_ldouble_infinite(ceil(LIB_MINUS_INF));
  ck_assert_ldouble_infinite(lib_ceil(LIB_MINUS_INF));
  ck_assert_ldouble_nan(ceil(LIB_NAN));
  ck_assert_ldouble_nan(lib_ceil(LIB_NAN));
}
START_TEST(floor_test) {
  ck_assert_ldouble_eq_tol(lib_floor(0.1), floor(0.1), E_6);
  ck_assert_ldouble_eq_tol(lib_floor(0.170), floor(0.170), E_6);
  ck_assert_ldouble_eq_tol(lib_floor(-0.1), floor(-0.1), E_6);
  ck_assert_ldouble_eq_tol(lib_floor(0.5), floor(0.5), E_6);
  ck_assert_ldouble_eq_tol(lib_floor(0.78), floor(0.78), E_6);
  ck_assert_ldouble_eq_tol(lib_floor(0), floor(0), E_6);
  ck_assert_ldouble_eq_tol(lib_floor(-77777), floor(-77777), E_6);
  ck_assert_ldouble_eq_tol(lib_floor(1234567), floor(1234567), E_6);
  ck_assert_ldouble_infinite(lib_floor(LIB_INF));
  ck_assert_ldouble_infinite(floor(LIB_INF));

  ck_assert_ldouble_infinite(floor(LIB_MINUS_INF));
  ck_assert_ldouble_infinite(lib_floor(LIB_MINUS_INF));
  ck_assert_ldouble_nan(floor(LIB_NAN));
  ck_assert_ldouble_nan(lib_floor(LIB_NAN));
}
START_TEST(pow_test) {
  ck_assert_ldouble_eq_tol(lib_pow(0, 1), pow(0, 1), E_6);
  ck_assert_ldouble_eq_tol(lib_pow(0, 0), pow(0, 0), E_6);
  ck_assert_ldouble_eq_tol(lib_pow(1, 0), pow(1, 0), E_6);
  ck_assert_ldouble_eq_tol(lib_pow(LIB_NAN, 0), pow(NAN, 0), E_6);

  ck_assert_ldouble_eq_tol(lib_pow(LIB_MINUS_INF, 0), pow(-INFINITY, 0), E_6);
  ck_assert_ldouble_eq(lib_pow(LIB_MINUS_INF, 1), pow(-INFINITY, 1));
  ck_assert_ldouble_eq(lib_pow(LIB_MINUS_INF, LIB_INF),
                       pow(-INFINITY, INFINITY));
  ck_assert_ldouble_eq_tol(lib_pow(LIB_MINUS_INF, LIB_MINUS_INF),
                           pow(-INFINITY, -INFINITY), E_6);

  ck_assert_ldouble_eq_tol(lib_pow(LIB_INF, 0), pow(INFINITY, 0), E_6);
  ck_assert_ldouble_eq(lib_pow(LIB_INF, 1), pow(INFINITY, 1));
  ck_assert_ldouble_eq(lib_pow(LIB_INF, LIB_INF), pow(INFINITY, INFINITY));
  ck_assert_ldouble_eq_tol(lib_pow(LIB_INF, LIB_MINUS_INF),
                           pow(INFINITY, -INFINITY), E_6);
  ck_assert_ldouble_nan(lib_pow(LIB_INF, LIB_NAN));

  ck_assert_ldouble_eq_tol(lib_pow(0.0034993283890293, 0),
                           pow(0.0034993283890293, 0), E_6);
  ck_assert_ldouble_eq(lib_pow(0.0034993283890293, LIB_MINUS_INF),
                       pow(0.0034993283890293, -INFINITY));
  ck_assert_ldouble_eq_tol(lib_pow(0.0034993283890293, LIB_INF),
                           pow(0.0034993283890293, INFINITY), E_6);

  long double input1 = 0.9999999999;
  long double input2 = 5.9999999999;
  int input3 = 100098;

  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      ck_assert_ldouble_eq_tol(lib_pow(input1, input2), pow(input1, input2),
                               E_6);
      input2 += 0.00004;

      ck_assert_ldouble_eq_tol(lib_pow(input1, input3), pow(input1, input3),
                               E_6);
      input3 += 153;
    }
  }
  ck_assert_ldouble_eq_tol(lib_pow(LIB_PI, 2), pow(LIB_PI, 2), E_6);
  ck_assert_ldouble_eq_tol(lib_pow(LIB_PI, 2), pow(LIB_PI, 2), E_6);
  ck_assert_ldouble_nan(pow(-2425432.7686, 7657.654));
}
END_TEST

START_TEST(log_test) {
  ck_assert_ldouble_eq_tol(lib_log(0.1), log(0.1), E_6);
  ck_assert_ldouble_eq_tol(lib_log(0.170), log(0.170), E_6);
  ck_assert_ldouble_eq_tol(lib_log(1.0), log(1.0), E_6);
  ck_assert_ldouble_eq_tol(lib_log(0.5), log(0.5), E_6);

  ck_assert_ldouble_infinite(lib_log(0.0));
  ck_assert_ldouble_infinite(log(0.0));

  ck_assert_ldouble_nan(lib_log(-9.0));
  ck_assert_ldouble_nan(log(-9.0));

  ck_assert_ldouble_eq_tol(lib_log(1234567), log(1234567), E_6);
  ck_assert_ldouble_infinite(lib_log(LIB_INF));
  ck_assert_ldouble_infinite(log(LIB_INF));

  ck_assert_ldouble_nan(lib_log(LIB_MINUS_INF));
  ck_assert_ldouble_nan(log(LIB_MINUS_INF));
  ck_assert_ldouble_nan(log(LIB_NAN));
  ck_assert_ldouble_nan(lib_log(LIB_NAN));
  END_TEST
}

int main(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("Math tests");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, fmod_test);
  tcase_add_test(tc_core, sin_test);
  tcase_add_test(tc_core, cos_test);
  tcase_add_test(tc_core, cos2_test);
  tcase_add_test(tc_core, abs_test);
  tcase_add_test(tc_core, fabs_test);
  tcase_add_test(tc_core, sin_test);
  tcase_add_test(tc_core, sin2_test);
  tcase_add_test(tc_core, tan_test);
  tcase_add_test(tc_core, atan_test);
  tcase_add_test(tc_core, exp_test);
  tcase_add_test(tc_core, sgrt_test);
  tcase_add_test(tc_core, arsin_test);
  tcase_add_test(tc_core, arcos_test);
  tcase_add_test(tc_core, ceil_test);
  tcase_add_test(tc_core, floor_test);
  tcase_add_test(tc_core, pow_test);
  tcase_add_test(tc_core, log_test);
  suite_add_tcase(s, tc_core);

  SRunner *runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);

  int nofailed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (nofailed == 0) ? 0 : 1;
}