#include "../lib_math.h"

long double lib_ceil(double x) {
  long long int tmp = x;

  if (x == LIB_INF)
    return LIB_INF;
  else if (x == LIB_MINUS_INF)
    return LIB_MINUS_INF;
  else if (x > 0) {
    if (tmp < x)
      return tmp + 1;
    else
      return tmp;
  } else if (x < 0) {
    return tmp;
  } else if (x != x)
    return LIB_NAN;
  else
    return 0;
}
