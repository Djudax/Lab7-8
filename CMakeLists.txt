cmake_minimum_required(VERSION 3.26)
project(7)

set(CMAKE_CXX_STANDARD 17)

add_executable(7 main.cpp
        DoubleLinkedlist.h
        SinglyLinkedlist.h
        DoubleNode.h
        SingleNode.h
        InputRestrictedQueue.h
        Queue.h
        Stack.h)
