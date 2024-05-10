#ifndef DATA_STRUCTURES_INPUTRESTRICTEDQUEUE_H
#define DATA_STRUCTURES_INPUTRESTRICTEDQUEUE_H

#include "Queue.h"

template <typename T>
class InputRestrictedQueue : public Queue<T> {
public:
    InputRestrictedQueue() {}

    InputRestrictedQueue(T data) : Queue<T>(data) {}

    void popBack() { this->queue.removeFromEnd(); }
};

#endif //DATA_STRUCTURES_INPUTRESTRICTEDQUEUE_H