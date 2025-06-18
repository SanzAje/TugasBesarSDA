#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "queue.h"
#include "operations.h" // Menggunakan fungsi operasi dasar

// Inisialisasi queue baru
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Menambah elemen ke belakang antrean (enqueue)
void enqueue(Queue* q, const char* data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    strncpy(newNode->data, data, 49);
    newNode->data[49] = '\0';
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Menghapus elemen dari depan antrean (dequeue)
char* dequeue(Queue* q) {
    if (isQueueEmpty(q)) return NULL;
    QueueNode* temp = q->front;
    char* data = (char*)malloc(50 * sizeof(char));
    strncpy(data, temp->data, 49);
    data[49] = '\0';

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Cek apakah queue kosong
bool isQueueEmpty(const Queue* q) {
    return q->front == NULL;
}

// Tampilkan isi queue (untuk debugging)
void displayQueue(const Queue* q) {
    QueueNode* current = q->front;
    printf("Isi Antrean: ");
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Helper untuk cek apakah string adalah operator
bool isOperator(const char* str) {
    return strcmp(str, "+") == 0 || strcmp(str, "-") == 0 || strcmp(str, "*") == 0 || strcmp(str, "/") == 0;
}

// Mengeksekusi seluruh operasi dalam queue
double executeQueue(Queue* q) {
    double stack[100]; // Stack sederhana untuk evaluasi RPN
    int top = -1;

    while (!isQueueEmpty(q)) {
        char* token = dequeue(q);
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            stack[++top] = atof(token); // atof: convert string to double
        } else if (isOperator(token)) {
            if (top < 1) {
                printf("Error: Ekspresi tidak valid dalam antrean.\n");
                free(token);
                return 0.0;
            }
            double val2 = stack[top--];
            double val1 = stack[top--];
            double result = 0;

            if (strcmp(token, "+") == 0) result = tambah(val1, val2);
            else if (strcmp(token, "-") == 0) result = kurang(val1, val2);
            else if (strcmp(token, "*") == 0) result = kali(val1, val2);
            else if (strcmp(token, "/") == 0) result = bagi(val1, val2);
            
            stack[++top] = result;
        }
        free(token);
    }

    if (top == 0) {
        return stack[top];
    } else {
        printf("Error: Format antrean tidak valid.\n");
        return 0.0;
    }
}