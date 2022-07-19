//
// Created by 杨文露 on 2021/9/26.
//

#ifndef DATA_STRUCTURE_CPP_DLLNODE_H
#define DATA_STRUCTURE_CPP_DLLNODE_H

template <typename T>
class DLLNode {
public:
    DLLNode() {
        next = prev = nullptr;
    }

    explicit DLLNode(const T& el, DLLNode<T> *n = nullptr, DLLNode<T> *p = nullptr) {
        info = el;
        next = n;
        prev = p;
    }


public:
    T info;
    DLLNode<T> *next, *prev;
};


#endif