#include <stdio.h>
#include <string>
#include <iostream>
#include "BSTFunctions.cpp"
#include <bits/stdc++.h>

using namespace std;


int main(){
    BSTIndexing Tree;
    fstream reader;
    

    Tree.printInOrder();


    // Tree.AddLeaf("hi");
    // Tree.AddLeaf("abigail");
    // Tree.AddLeaf("hello");
    // Tree.AddLeaf("amsterdam");
    // Tree.AddLeaf("hippy");
    // Tree.AddLeaf("hifive");
    //Tree.AddLeaf("Alexander");

    // for (int i = 0; i < Tree.returnWordArrayLength();i++){
    //     cout << Tree.returnWord(i) << endl;;
    // }

    Tree.addAllWordsFromTextFile("page.txt");
    Tree.printInOrder();


    return 0;
}