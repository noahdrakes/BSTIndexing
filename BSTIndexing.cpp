#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "BSTFunctions.cpp"

using namespace std;


int main(){
    BSTIndexing Tree;
    Tree.AddLeaf("hi");
    Tree.AddLeaf("abigail");
    Tree.AddLeaf("hello");
    Tree.AddLeaf("Amsterdam");
    Tree.AddLeaf("hippy");
    Tree.AddLeaf("hifive");
    //Tree.AddLeaf("Alexander");

    for (int i = 0; i < Tree.returnWordArrayLength();i++){
        cout << Tree.returnWord(i) << endl;;
    }

    return 0;
}