#ifndef HISTORY_H
#define HISTORY_H

#include <string>
using namespace std;

struct Node {
    string operasi;
    double hasil;
    Node* next;
};

class HistoryList {
private:
    Node* head;
public:
    HistoryList();
    void tambah(string operasi, double hasil);
    void tampilkan();
};

#endif
