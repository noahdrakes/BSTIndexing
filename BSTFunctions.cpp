#include "BSTIndexing.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;
    
    BSTIndexing::BSTIndexing(){
        root = NULL;
    }
    BSTIndexing::node* BSTIndexing::CreateLeaf(string key){
        node* newNode = new node;
        newNode->character = key[0];
        charactersUsed[CharactersUsedIndex] = key[0];
        CharactersUsedIndex++;



    }