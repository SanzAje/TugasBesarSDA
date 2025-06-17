#include "advanceOps.h"

long long faktorial(int n) {
    long long hasil = 1;
    for (int i = 1; i <= n; i++) {
        hasil *= i;
    }
    return hasil;
}

int fpb(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int kpk(int a, int b) {
    return (a * b) / fpb(a, b);
}

long long permutasi(int n, int r) {
    if (r > n || n < 0 || r < 0) return 0;
    return faktorial(n) / faktorial(n - r);
}

long long kombinasi(int n, int r) {
    if (r > n || n < 0 || r < 0) return 0;
    return faktorial(n) / (faktorial(r) * faktorial(n - r));
}