#include <iostream>
#include "operations.h"
#include "history.h"
#include "utils.h"

using namespace std;

int main() {
    HistoryList riwayat;
    int pilihan;
    double a, b, hasil;

    do {
        cout << "\n== Menu Kalkulator ==\n";
        cout << "1. Tambah\n2. Kurang\n3. Kali\n4. Bagi\n5. Sin\n6. Cos\n7. Tan\n";
        cout << "8. Log\n9. Akar\n10. Pangkat\n11. Faktorial\n12. Lihat Riwayat\n0. Keluar\n";
        cout << "Pilih: ";
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
            case 11:
                cin >> a;
                hasil = faktorial((int)a);
                riwayat.tambah("Faktorial", hasil);
                cout << "Hasil: " << hasil << endl;
                break;
            case 12:
                riwayat.tampilkan();
                break;
            case 0:
                cout << "Keluar...\n"; break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (pilihan != 0);

    return 0;
}
