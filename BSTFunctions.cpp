#include "BSTIndexing.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

void alphabeticalSort(string array[], int arraySize){
    string smallestElement;
    int index;
    string temp;

    cout << endl << "sorting Array of Strings of strings..." << endl;

    for (int i = 0; i < arraySize - 1; i++){
        smallestElement = array[i];
        for (int j = i; j < arraySize; j++){

            if (array[j] <=  smallestElement){
                smallestElement = array[j];
                index = j;
            }
        }
        
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }

}


void BSTIndexing::addWordPrivate(string key, node* Ptr){
    Ptr->words[Ptr->wordIndex] = key;
    Ptr->wordIndex++;
}

void BSTIndexing::addWord(string key, node* Ptr){
    addWordPrivate(key, Ptr);
}

    
BSTIndexing::BSTIndexing(){
    root = NULL;
}


    // CREATE LEAF
    //          * a leaf has no children *
BSTIndexing::node* BSTIndexing::CreateLeaf(string key){
    node* newNode = new node;
    newNode->character = key[0];
        // save character 

    // save word to array of words for that letter
    addWord(key, newNode);

    // sort word list
    alphabeticalSort(newNode->words, newNode->wordIndex);

    // NO need to sort the array in create leaf function
    // sort it in the create node function

    newNode->right = NULL;
    newNode->left = NULL;

    

    return newNode;
}


    void BSTIndexing::AddLeaf(string key){
        AddLeafPrivate(key, root);
    }


    void BSTIndexing::AddLeafPrivate(string key, node* Ptr){

        // if there is not root -> TREE DOESNT EXIST
        if (root == NULL){
            root = CreateLeaf(key);

        // if the first letter of the word passed is less than the first letter of the 
        // pointer passed
        } else if (key[0] < Ptr->character) {

            if (Ptr->left != NULL){
                
                AddLeafPrivate(key, Ptr->left);

            } else {
                Ptr->left = CreateLeaf(key);
            }    

        // if the first letter of the word passed is less than the first letter of the 
        // pointer passed
        } else if (key[0] > Ptr->character){

            if (Ptr->right != NULL) {

                AddLeafPrivate(key, Ptr->right);

            } else {
                Ptr->right = CreateLeaf(key);
            }

        // if key already exist add word to that letter
        } else {
            if ( Ptr->character == key[0] ){

                addWord(key, Ptr);
                alphabeticalSort(Ptr->words, Ptr->wordIndex);
                cout << "Ptr" << endl;

            }
            cout << "key [" << key << "] has ALREADY been added to tree" << endl;
        }


    }


int BSTIndexing::returnWordArrayLength(){
    return root->wordIndex;
}

string BSTIndexing::returnWord(int index){
    return root->words[index];
} 

void BSTIndexing::printInorderPrivate(node* Ptr){
    if (root != NULL){
        if (Ptr->left != NULL){
            printInorderPrivate(Ptr->left);
        } 

        cout << Ptr->character << endl;
        cout << "~" << endl;

        for(int i = 0; i < Ptr->wordIndex; i++){
            cout << Ptr->words[i] << endl;
        }

        cout << endl;

        if (Ptr->right != NULL){
            printInorderPrivate(Ptr->right);
        }
    } else {
        cout << "tree empty" << endl;
    }
}

void BSTIndexing::printInOrder(){
    printInorderPrivate(root);
}