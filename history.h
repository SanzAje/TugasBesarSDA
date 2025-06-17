#ifndef HISTORY_H
#define HISTORY_H

#define MAX_LEN 100

typedef struct Node {
    char operasi[MAX_LEN];
    double hasil;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} HistoryList;

void initRiwayat(HistoryList* list);
void tambahRiwayat(HistoryList* list, const char* operasi, double hasil);
void tampilkanRiwayat(const HistoryList* list);

#endif
