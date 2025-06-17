#include <math.h>
#include "operations.h"

double tambah(double a, double b) { return a + b; }
double kurang(double a, double b) { return a - b; }
double kali(double a, double b) { return a * b; }
double bagi(double a, double b) { return b != 0 ? a / b : 0; }
double sinus(double x) { return sin(x); }
double cosinus(double x) { return cos(x); }
double tangen(double x) { return tan(x); }
double log10_custom(double x) { return log10(x); }
double akar(double x) { return sqrt(x); }
double pangkat(double x, double y) { return pow(x, y); }
