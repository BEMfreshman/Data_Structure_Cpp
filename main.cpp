#include <iostream>

#include "SkipL.h"
#include "BinaryTree.h"

using std::cout;
using std::endl;

//int main () {
//    SkipList<int> SL;
//
//    SL.skipListInsert(1);
//    SL.skipListInsert(5);
//    SL.skipListInsert(8);
//
//    SL.skipListInsert(2);
//    SL.skipListInsert(11);
//    SL.skipListInsert(7);
//
//    SL.skipListInsert(1);
//    SL.skipListInsert(99);
//    SL.skipListInsert(50);
//
//    int* ptr = SL.skipListSearch(11);
//    if (ptr == nullptr) {
//        cout << "error" << endl;
//    }
//
//    ptr = SL.skipListSearch(57);
//
//    return 0;
//}

int main() {

    BinaryTreeNode<int> n12(12);
    BinaryTreeNode<int> n10(10);
    BinaryTreeNode<int> n11(11,nullptr,&n12);

    BinaryTreeNode<int> n9(9,&n10,&n11);
    BinaryTreeNode<int> n8(8);

    BinaryTreeNode<int> n7(7);
    BinaryTreeNode<int> n6(6);

    BinaryTreeNode<int> n5(5,nullptr, nullptr);
    BinaryTreeNode<int> n4(4,&n8,&n9);

    BinaryTreeNode<int> n3(3,&n6,&n7);
    BinaryTreeNode<int> n2(2,&n4,&n5);

    BinaryTree<int> tree(1,&n2,&n3);

    int deep = tree.getDeepth();

    cout << "deep is " << deep << endl;

    return 0;
}
