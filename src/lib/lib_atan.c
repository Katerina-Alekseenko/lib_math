#include "../lib_math.h"

long double lib_atan(double x) {
  if (x > 1) {
    return LIB_2_DEL_PI - lib_atan(1 / x);

  } else if (x < -1) {
    return -LIB_2_DEL_PI - lib_atan(1 / x);
  }
  long double res_old = LIB_NAN;
  long double num = x;

  long double res = x;
  long double index = 1;
  long double sign = 1;
  while (res != res_old && index < 50000) {
    res_old = res;

    num *= x * x;
    index++;
    sign *= -1;
    res += sign * num / (2 * index - 1);
  }
  return res;
}
