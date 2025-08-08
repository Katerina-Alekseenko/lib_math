#include <stdio.h>
#include <stdlib.h>

#define LIB_PI 3.14159265358979323846l
#define LIB_2_PI LIB_PI * 2
#define LIB_2_DEL_PI LIB_PI / 2
#define LIB_4_DEL_PI LIB_PI / 4

#define LIB_NAN (0.0 / 0.0)
#define LIB_INF (1.0 / 0.0)
#define LIB_MINUS_INF (-1.0 / 0.0)
#define E_6 1e-6
#define LIB_EPS 1E-9
#define LIB_EPS_E 1E-16
#define LIB_DBL_MAX 1.7976931348623158e+308
#define EXP 2.71828182845904

int lib_abs(int x);
long double lib_fabs(double x);
long double lib_pow(double base, double exp);
long double lib_fmod(double x, double y);
long double lib_cos(double x);
long double lib_sin(double x);
long double lib_tan(double x);
long double lib_atan(double x);
long double lib_exp(double x);
long double lib_sqrt(double x);
long double lib_asin(double x);
long double lib_acos(double x);
long double lib_ceil(double x);
long double lib_floor(double x);
long double lib_log(double x);