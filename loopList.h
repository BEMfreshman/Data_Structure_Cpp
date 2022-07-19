//
// Created by 杨文露 on 2021/9/26.
//

#ifndef DATA_STRUCTURE_CPP_LOOPLIST_H
#define DATA_STRUCTURE_CPP_LOOPLIST_H

#include "SLLNode.h"

template <typename T>
class loopList
{
public:
    loopList() {
        head = nullptr;
        tail = nullptr;
    }

    void addToTail(const T&);
    T deleteFromDLLTail();
    bool isemtpy() {
        return head == nullptr && tail == nullptr;
    }

protected:
    DLLNode<T> *head, *tail;
};

template <typename T>
void loopList<T>::addToTail(const T& el) {

}

#endif