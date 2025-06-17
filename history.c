#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

void initRiwayat(HistoryList* list) {
    list->head = NULL;
}

void tambahRiwayat(HistoryList* list, const char* operasi, double hasil) {
    Node* baru = (Node*)malloc(sizeof(Node));
    strncpy(baru->operasi, operasi, MAX_LEN - 1);
    baru->operasi[MAX_LEN - 1] = '\0';
    baru->hasil = hasil;
    baru->next = list->head;
    list->head = baru;
}

void tampilkanRiwayat(const HistoryList* list) {
    printf("\n--- Riwayat Perhitungan ---\n");
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%s = %.2lf\n", temp->operasi, temp->hasil);
        temp = temp->next;
    }
    printf("---------------------------\n");
}
