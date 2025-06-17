#include <iostream>
#include "operations.h"
#include "history.h"
#include "advanceOps.h"

using namespace std;

int main() {
    HistoryList riwayat;
    int pilihan;
    double a, b, hasil;

    do {
        cout << "\n== Menu Kalkulator Ilmiah ==\n";
        cout << "1. Tambah\n2. Kurang\n3. Kali\n4. Bagi\n";
        cout << "5. Sin\n6. Cos\n7. Tan\n8. Log\n9. Akar\n10. Pangkat\n";
        cout << "11. Faktorial\n12. Lihat Riwayat\n";
        cout << "13. FPB\n14. KPK\n15. Permutasi (nPr)\n16. Kombinasi (nCr)\n";
        cout << "0. Keluar\nPilih: ";
        cin >> pilihan;

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