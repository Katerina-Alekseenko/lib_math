#include "../lib_math.h"

long double lib_acos(double x) {
  if (x > 0) {
    return lib_atan(lib_sqrt(1 - x * x) / x);
  } else if (x < 0) {
    return LIB_PI + lib_atan(lib_sqrt(1 - x * x) / x);
  } else if (x == 0)
    return 1.57079633;
  else
    return LIB_NAN;
}
