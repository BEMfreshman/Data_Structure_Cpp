cmake_minimum_required(VERSION 3.17)
project(Data_Structure_Cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(Data_Structure_Cpp main.cpp genDLList.h /
                loopList.h DLLNode.h SLLNode.h SLList.h SkipL.h BinaryTree.h SBTree.cpp SBTree.h)