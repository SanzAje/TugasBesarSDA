#include "history.h"
#include <iostream>

HistoryList::HistoryList() {
    head = NULL;
}

void HistoryList::tambah(string operasi, double hasil) {
    Node* baru = new Node;
    baru->operasi = operasi;
    baru->hasil = hasil;
    baru->next = head;
    head = baru;
}

void HistoryList::tampilkan() {
    Node* temp = head;
    cout << "\n--- Riwayat Perhitungan ---\n";
    while (temp != NULL) {
        cout << temp->operasi << " = " << temp->hasil << endl;
        temp = temp->next;
    }
    cout << "---------------------------\n";
}
