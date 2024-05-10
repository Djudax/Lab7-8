#ifndef DATA_STRUCTURES_QUEUE_H
#define DATA_STRUCTURES_QUEUE_H

#include "DoubleLinkedList.h"

template <typename T>
class Queue {
protected:
    DoubleLinkedList<T> queue;
public:
    Queue() {}

    Queue(T data) : queue{DoubleLinkedList(data)} {}

    void enqueue(T data) { queue.insertAtEnd(data); }

    T dequeue() {
        T result = queue[0];
        queue.removeFromBeginning();
        return result;
    }

    T peek() { return queue[0]; }

    bool isEmpty() { return queue.isEmpty(); }
};

#endif //DATA_STRUCTURES_QUEUE_H