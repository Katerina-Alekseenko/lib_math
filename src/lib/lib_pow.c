#include "../lib_math.h"

long double lib_pow(double base, double exp) {
  long double result = 0;
  if (!exp) {
    return 1;
  } else if (base == LIB_MINUS_INF && exp == LIB_MINUS_INF) {
    return 0;
  } else if (base == LIB_MINUS_INF && exp == LIB_INF) {
    return LIB_INF;
  } else if (base < 0 && exp != (long long int)exp) {
    return LIB_MINUS_INF;
  } else if (base == LIB_NAN || exp == LIB_NAN) {
    return LIB_NAN;
  } else {
    if (base > 0) {
      result = lib_exp(exp * lib_log(base));
    } else if (base < 0) {
      base = lib_fabs(base);
      result = lib_exp(exp * lib_log(base));
      if (((int)exp % 2) != 0) result = -result;
    }
  }
  return result;
}
