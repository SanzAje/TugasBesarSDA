#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

// Node untuk Queue, menyimpan data sebagai string
typedef struct QueueNode {
    char data[50];
    struct QueueNode* next;
} QueueNode;

// Struktur Queue dengan pointer ke depan dan belakang
typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue();
void enqueue(Queue* q, const char* data);
char* dequeue(Queue* q);
bool isQueueEmpty(const Queue* q);
void displayQueue(const Queue* q);
double executeQueue(Queue* q); // Fungsi utama untuk mengeksekusi operasi

#endif