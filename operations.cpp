#include "operations.h"
#include <cmath>

double tambah(double a, double b) { return a + b; }
double kurang(double a, double b) { return a - b; }
double kali(double a, double b) { return a * b; }
double bagi(double a, double b) { return b != 0 ? a / b : 0; }
double sinus(double deg) { return sin(deg * M_PI / 180); }
double cosinus(double deg) { return cos(deg * M_PI / 180); }
double tangen(double deg) { return tan(deg * M_PI / 180); }
double log10_custom(double a) { return a > 0 ? log10(a) : 0; }
double akar(double a) { return a >= 0 ? sqrt(a) : 0; }
double pangkat(double a, double b) { return pow(a, b); }