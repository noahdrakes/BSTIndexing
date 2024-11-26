#include <stdio.h>
#include <string>
#include <iostream>
#include "BSTFunctions.cpp"

using namespace std;


int main(){
    BSTIndexing Tree;
    
    Tree.addAllWordsFromTextFile("page.txt");
    Tree.printInOrder();


    return 0;
}
