#include "../lib_math.h"

long double lib_fabs(double x) {
  x = x >= 0 ? x : -x;
  return (long double)x;
}