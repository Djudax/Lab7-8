#ifndef DATA_STRUCTURES_DOUBLENODE_H
#define DATA_STRUCTURES_DOUBLENODE_H

#include <memory>

namespace double_node {
    template<typename T>
    struct Node {
        T data;
        std::shared_ptr<Node<T>> next;
        std::weak_ptr<Node<T>> prev;

        Node(const T &value) : data{value}, next{nullptr} {};
    };
}

#endif //DATA_STRUCTURES_DOUBLENODE_H