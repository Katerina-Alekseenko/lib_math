#include "../lib_math.h"

long double lib_log(double x) {
  long double result = 0, compare = 0;
  int e_repeat = 0;
  if (x < 0) {
    return LIB_NAN;
  } else if (x == 0) {
    return LIB_MINUS_INF;
  } else if (x == LIB_INF) {
    return LIB_INF;
  } else if (x != x) {
    return LIB_NAN;
  } else if (x > 0) {
    for (; x >= EXP; e_repeat++) {
      x /= EXP;
    }
    for (int i = 0; i < 100; i++) {
      compare = result;
      result = compare + 2 * (x - lib_exp(compare)) / (x + lib_exp(compare));
    }
    result += e_repeat;
  }
  return result;
}