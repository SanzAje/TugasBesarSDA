#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "operations.h"
#include "advanceOps.h"
#include "history.h"

int main() {
    HistoryList riwayat;
    initRiwayat(&riwayat);

    int pilihan;
    double a, b, hasil;

    do {
        const char* kiri[] = {
            "1. Tambah", "2. Kurang", "3. Kali", "4. Bagi",
            "5. Sin", "6. Cos", "7. Tan", "8. Log"
        };
        const char* kanan[] = {
            "9. Akar", "10. Pangkat", "11. Faktorial", "12. Lihat Riwayat",
            "13. FPB", "14. KPK", "15. Permutasi (nPr)", "16. Kombinasi (nCr)"
        };

        printf("\n== Menu Kalkulator Ilmiah ==\n");
        for (int i = 0; i < 8; ++i) {
            printf("%-25s%s\n", kiri[i], kanan[i]);
        }

        printf("\n0. Keluar\nPilih: ");
        if (scanf("%d", &pilihan) != 1) {
            while (getchar() != '\n');
            printf("Input tidak valid! Masukkan angka.\n");
            continue;
        }

        switch (pilihan) {
            case 1: scanf("%lf %lf", &a, &b); hasil = tambah(a, b); tambahRiwayat(&riwayat, "Tambah", hasil); break;
            case 2: scanf("%lf %lf", &a, &b); hasil = kurang(a, b); tambahRiwayat(&riwayat, "Kurang", hasil); break;
            case 3: scanf("%lf %lf", &a, &b); hasil = kali(a, b); tambahRiwayat(&riwayat, "Kali", hasil); break;
            case 4: scanf("%lf %lf", &a, &b); hasil = bagi(a, b); tambahRiwayat(&riwayat, "Bagi", hasil); break;
            case 5: scanf("%lf", &a); hasil = sinus(a); tambahRiwayat(&riwayat, "Sinus", hasil); break;
            case 6: scanf("%lf", &a); hasil = cosinus(a); tambahRiwayat(&riwayat, "Cosinus", hasil); break;
            case 7: scanf("%lf", &a); hasil = tangen(a); tambahRiwayat(&riwayat, "Tangen", hasil); break;
            case 8: scanf("%lf", &a); hasil = log10_custom(a); tambahRiwayat(&riwayat, "Log", hasil); break;
            case 9: scanf("%lf", &a); hasil = akar(a); tambahRiwayat(&riwayat, "Akar", hasil); break;
            case 10: scanf("%lf %lf", &a, &b); hasil = pangkat(a, b); tambahRiwayat(&riwayat, "Pangkat", hasil); break;
            case 11: scanf("%lf", &a); hasil = faktorial((int)a); tambahRiwayat(&riwayat, "Faktorial", hasil); break;
            case 12: tampilkanRiwayat(&riwayat); break;
            case 13: scanf("%lf %lf", &a, &b); hasil = fpb((int)a, (int)b); tambahRiwayat(&riwayat, "FPB", hasil); break;
            case 14: scanf("%lf %lf", &a, &b); hasil = kpk((int)a, (int)b); tambahRiwayat(&riwayat, "KPK", hasil); break;
            case 15: scanf("%lf %lf", &a, &b); hasil = permutasi((int)a, (int)b); tambahRiwayat(&riwayat, "Permutasi", hasil); break;
            case 16: scanf("%lf %lf", &a, &b); hasil = kombinasi((int)a, (int)b); tambahRiwayat(&riwayat, "Kombinasi", hasil); break;
            case 0: printf("Keluar dari program...\n"); break;
            default: printf("Pilihan tidak valid!\n"); break;
        }

        if (pilihan >= 1 && pilihan <= 16) {
            printf("Hasil: %.2lf\n", hasil);
        }

    } while (pilihan != 0);

    return 0;
}
