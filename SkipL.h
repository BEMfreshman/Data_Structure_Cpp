#ifndef _SKIP_H_
#define _SKIP_H_

const int maxLevel = 4;

template <typename T>
class SkipListNode {

public:
    SkipListNode() {};

    T key;
    SkipListNode **next;
};

template <typename T>
class SkipList
{
public:
    SkipList(/* args */);
    
    bool isEmpty() const;
    void choosePowers();
    int  chooseLevel();
    T*   skipListSearch(const T&);
    void skipListInsert(const T&);

private:
    typedef SkipListNode<T> *nodePtr;
    nodePtr root[maxLevel];
    int powers[maxLevel];
};

template <typename T>
SkipList<T>::SkipList(/* args */)
{
    for (int i = 0; i< maxLevel; i++) {
        root[i] = nullptr;
    }

    choosePowers();
}

template <typename T>
bool SkipList<T>::isEmpty() const {
    return root[0] == nullptr;
}

template <typename T>
void SkipList<T>::choosePowers() {
    powers[maxLevel - 1] = ( 2 << (maxLevel - 1)) - 1;
    for (int i = maxLevel - 2, j = 0; i >= 0; i-- , j++) {
        powers[i] = powers[i + 1] -  (2 << j);   // 2 ^ (j + 1)
    }
}

template <typename T>
int SkipList<T>::chooseLevel() {
    int i ,r = rand() % powers[maxLevel - 1] + 1;
    for (i  = 1; i < maxLevel ;i++) {
        if (r < powers[i]) {
            return i - 1;
        }
    }

    return  maxLevel - 1;
}

template <typename T>
T* SkipList<T>::skipListSearch(const T& el) {
    if (isEmpty()) return nullptr;
    nodePtr curr, prev;

    int lvl;
    for (lvl = maxLevel - 1; lvl >=0 && root[lvl]==nullptr;lvl--);
    curr = prev = root[lvl];
    while(true) {
        if (curr->key == el) {
            return &(curr->key);
        }
        else if (curr->key < el) {
            prev = curr;
            if (*(curr->next + lvl) != nullptr) {
                curr = *(curr->next + lvl);
            }
            else {
                // goto next level
                for (lvl--; lvl >= 0 && *(curr->next+lvl)==nullptr; lvl--);
                if (lvl >= 0) {
                    curr = *(curr->next + lvl);
                }
                else {
                    return nullptr;
                }
            }
        }
        else {
            if (lvl == 0) {
                return nullptr;
            }
            else if (curr == root[lvl]) {
                curr = root[--lvl];
            }
            else {
                curr = *(prev->next + (--lvl));
            }
        }
    }
}

template <typename T>
void SkipList<T>::skipListInsert(const T& key) {

    int lvl;
    nodePtr curr[maxLevel], prev[maxLevel], newnode;

    for (int i = 0; i < maxLevel; i++) {
        curr[i] = nullptr;
        prev[i] = nullptr;
    }

    curr[maxLevel - 1] = root[maxLevel - 1];
    prev[maxLevel - 1] = nullptr;

    for (lvl = maxLevel - 1; lvl >= 0; lvl --) {
        while (curr[lvl] && curr[lvl]->key < key) {
            prev[lvl] = curr[lvl];
            curr[lvl] = *(curr[lvl]->next + lvl);
        }

        if (curr[lvl] && curr[lvl]->key == key) return;

        if (lvl > 0) {
            if (prev[lvl] == nullptr) {
                curr[lvl - 1] = root[lvl - 1];
                prev[lvl - 1] = nullptr;
            }
            else {
                curr[lvl - 1] = *(prev[lvl]->next+lvl - 1);
                prev[lvl - 1] = prev[lvl];
            }
        }
    }

    lvl = chooseLevel();
    newnode = new SkipListNode<T>();
    newnode->next = new nodePtr[sizeof(nodePtr) * (lvl + 1)];
    newnode->key = key;
    for (int i = 0; i <= lvl; i++) {
        *(newnode->next + i) = curr[i];
        if (prev[i] == nullptr)
            root[i] = newnode;
        else *(prev[i]->next + i) = newnode;
    }
}

#endif