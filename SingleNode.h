#ifndef DATA_STRUCTURES_SINGLENODE_H
#define DATA_STRUCTURES_SINGLENODE_H

#include <memory>

namespace single_node {
    template<typename T>
    struct Node {
        T data;
        std::unique_ptr<Node<T>> next;

        Node(const T &value) : data{value}, next{nullptr} {};
    };
}

#endif //DATA_STRUCTURES_SINGLENODE_H