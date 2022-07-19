//
// Created by 杨文露 on 2021/9/26.
//

#ifndef DATA_STRUCTURE_CPP_SLLIST_H
#define DATA_STRUCTURE_CPP_SLLIST_H

#include "SLLNode.h"

template <typename T>
class SLList {
public:
    SLList() {
        head = nullptr;
        tail = nullptr;
    }

    ~SLList(); // clear this list;

    bool isempty() const {
        return head == nullptr;
    }

    void addToHead(const T&);
    void addToTail(const T&);
    T deleteFromHead();
    T deleteFromTail();

protected:
    SLLNode<T> *head, *tail;
};

template <typename T>
SLList<T>::~SLList() {

    for (SLLNode<T> *p; !isempty();) {
        p = head->next;
        delete head;
        head = p;
    }
}

template <typename T>
void SLList<T>::addToTail(const T& el) {
    if (tail == nullptr) {
        tail = new SLLNode(el);
    }
    else {
        tail->next = new SLLNode(el);
    }
}

template <typename T>
void SLList<T>::addToHead(const T& el) {
    head = new SLLNode(el,head);
}

template <typename T>
T SLList<T>::deleteFromHead() {
    if (head == nullptr) {
        return T(0);
    }
    else {
        T info = head->info;
        SLLNode<T> *node = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
        }
        delete node;
        return info;
    }
}

template <typename T>
T SLList<T>::deleteFromTail() {
    if (tail == nullptr) {
        return T(0);
    }
    else {
        T info = tail->info;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            for (SLLNode<T> *p = head; p != tail; p=p->next);
            tail = p;
            delete tail->next;
            tail->next = nullptr;
        }

        return info;
    }
}


#endif