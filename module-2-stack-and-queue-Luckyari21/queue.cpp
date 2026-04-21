#include "queue.h"
#include <stdexcept>

// front menunjuk elemen terdepan, rear menunjuk elemen terbelakang.
// Kondisi kosong: front > rear (rear dimulai sebelum front).
void init(Queue* q) {
    q->front = q->data;
    q->rear  = q->data - 1;
}

bool isEmpty(const Queue* q) {
    return q->front > q->rear;
}

bool isFull(const Queue* q) {
    return q->rear >= q->data + MAX - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q))
        throw std::overflow_error("Queue penuh: tidak dapat melakukan enqueue");
    *(++q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q))
        throw std::underflow_error("Queue kosong: tidak dapat melakukan dequeue");
    q->front++;
}

int front(const Queue* q) {
    if (isEmpty(q))
        throw std::underflow_error("Queue kosong: tidak dapat mengakses front");
    return *(q->front);
}

int back(const Queue* q) {
    if (isEmpty(q))
        throw std::underflow_error("Queue kosong: tidak dapat mengakses back");
    return *(q->rear);
}