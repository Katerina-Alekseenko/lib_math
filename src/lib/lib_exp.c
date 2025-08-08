#include "../lib_math.h"

long double lib_exp(double x) {
  long double add_value = 1;
  long double i = 1;
  long double result = 1;
  int sign_x = 0;
  if (x == LIB_INF) {
    result = LIB_INF;
  } else if (x == LIB_MINUS_INF) {
    result = LIB_MINUS_INF;
  } else if (x == LIB_NAN) {
    result = LIB_NAN;
  } else if (x == 0) {
    result = 1;
  } else {
    if (x < 0) {
      x = lib_fabs(x);
      sign_x = 1;
    }
    while (lib_fabs(add_value) > LIB_EPS && result < LIB_DBL_MAX) {
      add_value *= x / i;
      i += 1;
      result += add_value;
    }
    if (sign_x) result = 1 / result;
  }
  if (result > LIB_DBL_MAX) {
    result = LIB_INF;
  } else if (result < LIB_EPS_E) {
    result = 0;
  }
  return result;
}
