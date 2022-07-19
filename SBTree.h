//
// Created by wenluyang on 2022/7/8.
//

#ifndef DATA_STRUCTURE_CPP_SBTREE_H
#define DATA_STRUCTURE_CPP_SBTREE_H


template <typename T> class SBTNode {
public:
    SBTNode() {
        lc = rc = parent = nullptr;
        data = (T)0;
    }

    explicit SBTNode(const T& d) {
        lc = rc = parent = nullptr;
        data = d;
    }

    ~SBTNode() = default;

    SBTNode<T>* GetLC() const {return lc;}
    SBTNode<T>* GetRC() const {return rc;}
    SBTNode<T>* GetParnet() const {return parent;}

    void SetLc(SBTNode<T>* n) {
        lc = n;
    }

    void SetRc(SBTNode<T>* n) {
        rc = n;
    }

    void SetParent(SBTNode<T>* p) {
        parent = p;
    }

    T GetData() const {return data;}

protected:

    SBTNode<T> *lc, *rc, *parent;
    T data;
};

template <typename T>
class SBTree {
public:
    SBTree() {
        root = nullptr;
    }

    explicit SBTree(const T& data) {
        root = new SBTNode<T>(data);
    }

    ~SBTree()
    {
        DestroyNode(root);
    }

    void visit(SBTNode<T>* node) const {

    }

    void inSort(SBTNode<T>* node) {
        if (node != nullptr) {
            inSortPrt(node->GetLC());
            visit(node);
            inSortPrt(node->GetRC());
        }
    }

    void insert(SBTNode<T>* node) {
        SBTNode<T>* cur = root, *prev = nullptr;
        const T& d = node->GetData();
        if (cur == nullptr) {
            root = node;
            return;
        }
        else {
            while(cur != nullptr) {
                prev = cur ;
                if (d < cur->GetData()) {
                    // go to its left
                    cur = cur->GetLC();
                }
                else if (d == cur->GetData()) {
                    return;
                }
                else {
                    // go to its right
                    cur = cur->GetRC();
                }
            }

            node->SetParent(prev);
            if (d < prev->GetData()) {
                prev->SetLc(node);
            }
            else {
                prev->GetRC(node);
            }
        }
    }

    void del(SBTNode<T>* node) {
        if (node == nullptr) return;
        SBTNode<T>* par = node->GetParnet();

        if (node->GetRC() == nullptr && node->GetLC() == nullptr) {

            if (par == nullptr) {
                // this is root
                root = nullptr;
                return;
            }

            if (node->GetData() < par->GetData()) {
                // left
                par->SetLc(nullptr);
            }
            else {
                // right
                par->SetRc(nullptr);
            }
        }
        else if (node->GetLC() == nullptr) {
            // only right tree
            SBTNode<T>* child = node->GetRC();
            if (par == nullptr) {
                child->SetParent(nullptr);
                root = child;
            }

            if (node->GetData() < par->GetData()) {
                // left
                par->SetLc(child);
                child->SetParent(par);
            }
            else {
                par->SetRc(child);
                child->SetParent(par);
            }

            node->SetParent(nullptr);
            node->SetRc(nullptr);

        }
        else if (node->GetRC() == nullptr) {
            // only left tree
            SBTNode<T>* child = node->GetLC();
            if (par == nullptr) {
                child->SetParent(nullptr);
                root = child;
            }

            if (node->GetData() < par->GetData()) {
                // left
                par->SetLc(child);
                child->SetParent(par);
            }
            else {
                par->SetRc(child);
                child->SetParent(par);
            }

            node->SetParent(nullptr);
            node->SetLc(nullptr);
        }
        else {
            // left and right
            SBTNode<T>* temp, *curP;
            temp = node->GetLC();
            curP = temp;
            while(temp != nullptr) {
                curP = temp;
                temp = temp->GetRC();
            }
            curP->SetRc(node->GetRC());

            node->GetLC()->SetParent(par);
            if (node->GetData() < par->GetData()) {
                par->SetLc(node->GetLC());
            }
            else {
                par->SetRc(node->GetLC());
            }
        }
    }

protected:
    void DestroyNode(SBTNode<T>* node) {
        if (node == nullptr) return;

        DestroyNode(node->GetLC());
        DestroyNode(node->GetRC());

        delete node;
        node = nullptr;
    }

protected:

    SBTNode<T>* root;
};


#endif //DATA_STRUCTURE_CPP_SBTREE_H
