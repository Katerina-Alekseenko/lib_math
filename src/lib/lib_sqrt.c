#include "../lib_math.h"

long double lib_sqrt(double x) {
  long double value_start = 1;
  long double res = x;
  long double exactitude = LIB_NAN;
  if (res < 0) {
    return LIB_NAN;
  }
  if (res == 0) {
    return 0;
  }
  if (x != x) {
    return LIB_NAN;
  }

  while (res != exactitude) {
    exactitude = res;
    res = (value_start + res) / 2;
    value_start = x / res;
  }
  return res;
}