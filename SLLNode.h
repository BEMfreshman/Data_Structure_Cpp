//
// Created by 杨文露 on 2021/9/26.
//

#ifndef DATA_STRUCTURE_CPP_SLLNODE_H
#define DATA_STRUCTURE_CPP_SLLNODE_H

template <typename T>
class SLLNode {
public:
    SLLNode() {
        next = nullptr;
    }

    explicit SLLNode(const T& el, SLLNode<T> *n = nullptr) {
        info el;
        next = n;
    }

public:
    T info;
    SLLNode<T> *next;
};

#endif