#include "../lib_math.h"

long double lib_asin(double x) {
  if (x <= 1 && x >= -1) {
    return lib_atan(x / lib_sqrt(1 - x * x));
  }
  return LIB_NAN;
}