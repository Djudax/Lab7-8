#ifndef DATA_STRUCTURES_SINGLYLINKEDLIST_H
#define DATA_STRUCTURES_SINGLYLINKEDLIST_H

#include <ostream>
#include "SingleNode.h"

template<typename T>
class SinglyLinkedList {
    std::unique_ptr<single_node::Node<T>> head;
    int size;
public:
    SinglyLinkedList() : head{nullptr}, size{0} {}

    SinglyLinkedList(T data) : head{std::make_unique<single_node::Node<T>>(data)}, size{1} {}

    void insertAtBeginning(T data) {
        std::unique_ptr<single_node::Node<T>> newNode = std::make_unique<single_node::Node<T>>(data);
        newNode->next = std::move(head);
        head = std::move(newNode);
        size++;
    }

    void insertAtEnd(T data) {
        std::unique_ptr<single_node::Node<T>> newNode = std::make_unique<single_node::Node<T>>(data);
        single_node::Node<T> *current = head.get();
        if (!current) {
            head = std::move(newNode);
            size++;
            return;
        }
        while (current->next) {
            current = current->next.get();
        }
        current->next = std::move(newNode);
        size++;
    }

    void removeFromBeginning() {
        if (!head) throw std::out_of_range("List is empty!");

        head = std::move(head->next);
        size--;
    }

    void removeFromEnd() {
        if (!head) throw std::out_of_range("List is empty!");

        if (size == 1) {
            head.reset();
            size--;
            return;
        }

        single_node::Node<T> *current = head.get();
        while (current->next->next) {
            current = current->next.get();
        }
        current->next.reset();
        size--;
    }

    T operator[](int index) {
        if (index < 0 || index > size - 1) throw std::out_of_range("Index is out of range");

        single_node::Node<T> *current = head.get();
        for (int i = 1; i <= index; i++) {
            current = current->next.get();
        }
        return current->data;
    }

    void insertAtIndex(T data, int index) {
        if (index == 0) {
            insertAtBeginning(data);
            return;
        }

        if (index == size) {
            insertAtEnd(data);
            return;
        }

        if (index < 0 || index > size - 1) throw std::out_of_range("Index is out of range");

        std::unique_ptr<single_node::Node<T>> newNode = std::make_unique<single_node::Node<T>>(data);
        single_node::Node<T> *previous = head.get();
        for (int i = 1; i <= index - 1; i++) {
            previous = previous->next.get();
        }
        newNode->next = std::move(previous->next);
        previous->next = std::move(newNode);
        size++;
    }

    void removeAtIndex(int index) {
        if (index < 0 || index > size - 1) throw std::out_of_range("Index is out of range");

        if (index == 0) {
            removeFromBeginning();
            return;
        }
        if (index == size - 1) {
            removeFromEnd();
            return;
        }

        single_node::Node<T> *previous = head.get();
        for (int i = 1; i <= index - 1; i++) {
            previous = previous->next.get();
        }
        previous->next = std::move(previous->next->next);
        size--;
    }

    int getSize() const { return size; }

    bool isEmpty() const { return size == 0; }

    int find(T search) {
        single_node::Node<T> *current = head.get();
        int index = 0;
        while (current) {
            if (search == current->data) return index;
            current = current->next.get();
            index++;
        }
        return -1;
    }

    friend std::ostream &operator<<(std::ostream &os, const SinglyLinkedList &list) {
        single_node::Node<T> *current = list.head.get();
        while (current) {
            os << current->data << " ";
            current = current->next.get();
        }
        os << std::endl;
        return os;
    }
};

#endif //DATA_STRUCTURES_SINGLYLINKEDLIST_H