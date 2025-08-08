#include "../lib_math.h"

long double lib_cos(double x) {
  if (x == LIB_INF || x == LIB_MINUS_INF) {
    return LIB_NAN;
  }
  if (x != x) {
    return LIB_NAN;
  }
  x = lib_fabs(lib_fmod(x, LIB_2_PI));
  long double j = 1;
  long double res = 1;
  if (x > LIB_PI) {
    x = x - LIB_PI;
    j = -1;
    res = -1;
  }
  long double res_old = 2;
  long double divisible = 1;
  long double divider = 1;
  long double i = 2;

  while (res != res_old) {
    res_old = res;

    divisible *= x * x;
    divider = divider * i * (i - 1);
    i += 2;
    j = j * -1;
    res += j * divisible / divider;
  }
  return res;
}
