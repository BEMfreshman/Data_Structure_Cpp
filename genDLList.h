//
// Created by 杨文露 on 2021/9/26.
//

#ifndef DATA_STRUCTURE_CPP_GENDLLIST_H
#define DATA_STRUCTURE_CPP_GENDLLIST_H

#include "DLLNode.h"


template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList();

    bool isempty() const {
        return head == nullptr;
    }

    void addToDLLTail(const T&);
    T deleteFromDLLTail();

protected:
    DLLNode<T> *head, *tail;
};

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    
    for (DLLNode<T> *p = head; !isempty();) {
        p = head->next;
        delete head;
        p->prev = nullptr;
        head = p;
    }
}

template <typename T>
void DoublyLinkedList<T>::addToDLLTail(const T& el) {
    if (tail != nullptr) {
        tail = new DLLNode<T>(el,nullptr,tail);
        tail->prev->next = tail;
    }
    else {
        // first node
        head = tail = new DLLNode<T>(el,nullptr,nullptr);
    }
}

template <typename T>
T DoublyLinkedList<T>::deleteFromDLLTail() {
    
    if(tail == nullptr)  {
        // in fact, there should be an error
        return T(0);
    }
    
    T info = tail->info;

    if (head == tail) {
        // only one
        delete head;
        head = tail = nullptr;
    }
    else {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }

    return info;

}





#endif //DATA_STRUCTURE_CPP_GENDLLIST_H
