//
// Created by wenluyang on 2022/6/25.
//

#ifndef DATA_STRUCTURE_CPP_BINARYTREE_H
#define DATA_STRUCTURE_CPP_BINARYTREE_H

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template <typename  T>
class BinaryTreeNode {
public:

    BinaryTreeNode() {
        lc = nullptr;
        rc = nullptr;
    }

    explicit BinaryTreeNode(const T& data) {
        this->data = data;
        lc = nullptr;
        rc = nullptr;
    }

    BinaryTreeNode(const T& data, BinaryTreeNode<T>* lc, BinaryTreeNode<T>* rc) {
        this->data = data;
        this->lc = lc;
        this->rc = rc;
    }

    T GetData() const {return data;}
    BinaryTreeNode<T>* GetLC() const {return lc;}
    BinaryTreeNode<T>* GetRC() const {return rc;}





protected:
    T data;
    BinaryTreeNode *lc;
    BinaryTreeNode *rc;
};

template <typename T>
class SeqBT {
public:
    SeqBT(int nodes): data (nullptr) {
        if (nodes > 0) {
            maxNode = nodes;
            data = new T[maxNode];
        }
    }

    ~SeqBT() {
        if (data) {
            delete data;
            data = nullptr;
        }
    }

protected:
    int maxNode;
    T*  data;
};

template <typename T>
class BinaryTree
{
public:
    BinaryTree()
        : root(new BinaryTreeNode<T>())
    {

    }

    explicit BinaryTree(const T& rD)
        : root (new BinaryTreeNode<T>(rD))
    {

    }

    BinaryTree(const T& rd,BinaryTreeNode<T>* lc, BinaryTreeNode<T>* rc)
        : root(new BinaryTreeNode<T>(rd,lc,rc))
    {

    }

    ~BinaryTree() {
        delete root;
        root = nullptr;
    }

    BinaryTreeNode<T>* ParentNode(BinaryTreeNode<T>* node) const ;

    void preOrder(BinaryTreeNode<T>* node);
    void layOrder(BinaryTreeNode<T>* node);

    int getDeepth() const;

protected:

    void destroyNode(BinaryTreeNode<T>* node) {
        if (node == nullptr) return;

        destroyNode(node->GetLC());
        destroyNode(node->GetRC());
        delete node;
        node = nullptr;
    }

protected:

    BinaryTreeNode<T>* root;
};

template <typename T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>* node) {
    if (node != nullptr) {
        cout << root->GetData() << endl;
        preOrder(node->GetLC());
        preOrder(node->GetRC());
    }
}

template <typename T>
void BinaryTree<T>::layOrder(BinaryTreeNode<T> *node) {
    queue<BinaryTreeNode<T> > que;
    que.push(node);

    BinaryTreeNode<T>* cur;

    while(!que.empty()) {
        cur = que.front();
        que.pop();
        cout << cur->GetData() << endl;

        if (node->GetLC()) {
            que.push(node->GetLC());
        }

        if (node->GetRC()) {
            que.push(node->GetRC());
        }
    }
}

template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::ParentNode(BinaryTreeNode<T> *node) const {
    if (node == nullptr || node == root) {
        return nullptr;
    }

    queue<BinaryTreeNode<T>* > que;
    que.push(root);
    BinaryTreeNode<T>* cur;
    BinaryTreeNode<T>* lc;
    BinaryTreeNode<T>* rc;

    while(!que.empty()) {
        cur = que.front();
        que.pop();

        lc = cur->GetLC();
        rc = cur->GetRC();

        if (lc) {
            if (lc == node) {
                return cur;
            }

            que.push(lc);
        }

        if (rc) {
            if (rc == node) {
                return cur;
            }

            que.push(rc);
        }
    }

    return nullptr;
}

template <typename T>
int BinaryTree<T>::getDeepth() const {
    stack<BinaryTreeNode<T>* > stk;
    stack<int> deepths;

    int cur_deep;
    int max_deep = 0;

    if (root == nullptr) {
        return 0;
    }

    cur_deep = 1;

    BinaryTreeNode<T>* cur_node = root;

    while (!(cur_node == nullptr && stk.empty())) {

        while(cur_node != nullptr) {
            stk.push(cur_node);
            deepths.push(cur_deep);
            cur_node = cur_node->GetLC();
            cur_deep++;
        }

        cur_node = stk.top();
        cur_deep = deepths.top();

        stk.pop();
        deepths.pop();

        if (cur_node->GetLC() == nullptr && cur_node->GetRC() == nullptr) {
            // leaf
            if (cur_deep >= max_deep) { max_deep = cur_deep;}
        }

        cur_node = cur_node->GetRC();
        cur_deep++;

    }

    return max_deep;
}

#endif //DATA_STRUCTURE_CPP_BINARYTREE_H
