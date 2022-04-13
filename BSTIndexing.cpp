#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "BSTFunctions.cpp"

using namespace std;


int main(){
    BSTIndexing Tree;

    Tree.printInOrder();


    Tree.AddLeaf("hi");
    Tree.AddLeaf("abigail");
    Tree.AddLeaf("hello");
    Tree.AddLeaf("amsterdam");
    Tree.AddLeaf("hippy");
    Tree.AddLeaf("hifive");
    //Tree.AddLeaf("Alexander");

    // for (int i = 0; i < Tree.returnWordArrayLength();i++){
    //     cout << Tree.returnWord(i) << endl;;
    // }

    Tree.printInOrder();


    return 0;
}