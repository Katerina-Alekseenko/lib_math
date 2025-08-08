#include "../lib_math.h"

int lib_is_inf(long double a) { return a == LIB_INF || a == LIB_MINUS_INF; }

long double lib_fmod(double x, double y) {
  if (y == 0)
    return LIB_NAN;
  else if (lib_is_inf(x))
    return LIB_NAN;
  else if (lib_is_inf(y) && !lib_is_inf(x))
    return x;

  int z = x / y;
  return (long double)x - (long double)y * (long double)z;
}