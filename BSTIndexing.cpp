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

    return 0;
}