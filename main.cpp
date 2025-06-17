#include <iostream>
#include "operations.h"
#include "history.h"
#include "advanceOps.h"
#include <iomanip>

using namespace std;

int main() {
    HistoryList riwayat;
    int pilihan;
    double a, b, hasil;

    do {
    cout << "\n== Menu Kalkulator Ilmiah ==\n";
    string kiri[] = {
        "1. Tambah", "2. Kurang", "3. Kali", "4. Bagi",
        "5. Sin", "6. Cos", "7. Tan", "8. Log"
    };
    string kanan[] = {
        "9. Akar", "10. Pangkat", "11. Faktorial", "12. Lihat Riwayat",
        "13. FPB", "14. KPK", "15. Permutasi (nPr)", "16. Kombinasi (nCr)"
    };

    for (int i = 0; i < 8; ++i) {
        cout << std::left << std::setw(25) << kiri[i] << kanan[i] << '\n';
    }

    cout << "\n0. Keluar\nPilih: ";
    cin >> pilihan;

    // Cek validitas input
    if (cin.fail()) {
        cin.clear(); // Reset error flag
        cin.ignore(1000, '\n'); // Buang sisa input
        cout << "Input tidak valid! Masukkan angka.\n";
        continue; // ulangi menu
    }

        switch (pilihan) {
            case 1:
                cin >> a >> b;
                hasil = tambah(a, b);
                riwayat.tambah("Tambah", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 2:
                cin >> a >> b;
                hasil = kurang(a, b);
                riwayat.tambah("Kurang", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 3:
                cin >> a >> b;
                hasil = kali(a, b);
                riwayat.tambah("Kali", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 4:
                cin >> a >> b;
                hasil = bagi(a, b);
                riwayat.tambah("Bagi", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 5:
                cin >> a;
                hasil = sinus(a);
                riwayat.tambah("Sinus", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 6:
                cin >> a;
                hasil = cosinus(a);
                riwayat.tambah("Cosinus", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 7:
                cin >> a;
                hasil = tangen(a);
                riwayat.tambah("Tangen", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 8:
                cin >> a;
                hasil = log10_custom(a);
                riwayat.tambah("Log", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 9:
                cin >> a;
                hasil = akar(a);
                riwayat.tambah("Akar", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 10:
                cin >> a >> b;
                hasil = pangkat(a, b);
                riwayat.tambah("Pangkat", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 11:
                cin >> a;
                hasil = faktorial((int)a);
                riwayat.tambah("Faktorial", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 12:
                riwayat.tampilkan();
                break;
            case 13:
                cin >> a >> b;
                hasil = fpb((int)a, (int)b);
                riwayat.tambah("FPB", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 14:
                cin >> a >> b;
                hasil = kpk((int)a, (int)b);
                riwayat.tambah("KPK", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 15:
                cin >> a >> b;
                hasil = permutasi((int)a, (int)b);
                riwayat.tambah("Permutasi", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 16:
                cin >> a >> b;
                hasil = kombinasi((int)a, (int)b);
                riwayat.tambah("Kombinasi", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 0:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}