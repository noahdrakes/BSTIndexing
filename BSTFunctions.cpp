#include "BSTIndexing.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;


// SELECTION SORT
void alphabeticalSort(string array[], int arraySize, int lineNumberArray[] ){
    string smallestElement;
    int indexSmallestElement;

    int index;
    string temp;
    
    int temp1;
    int index1;


    for (int i = 0; i < arraySize - 1; i++){
        smallestElement = array[i];
        indexSmallestElement = lineNumberArray[i];
        for (int j = i; j < arraySize; j++){

            if (array[j] <=  smallestElement){
                smallestElement = array[j];
                indexSmallestElement = lineNumberArray[j];
                index1 = j;
                index = j;
            }
        }
        
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;

        temp1 = lineNumberArray[i];
        lineNumberArray[i] = lineNumberArray[index1];
        lineNumberArray[index1] = temp1;
    }

}


void BSTIndexing::addWordPrivate(string key, node* Ptr, int lineNumber){
    Ptr->words[Ptr->wordIndex] = key;
    Ptr->wordIndex++;

    Ptr->lineNumber[Ptr->lineNumberIndex] = lineNumber;
    Ptr->lineNumberIndex++;
}

void BSTIndexing::addWord(string key, node* Ptr, int lineNumber){
    addWordPrivate(key, Ptr, lineNumber);
}

    
BSTIndexing::BSTIndexing(){
    root = NULL;
}


    // CREATE LEAF
    //          * a leaf has no children *
BSTIndexing::node* BSTIndexing::CreateLeaf(string key, int lineNumber){
    node* newNode = new node;
    newNode->character = key[0];
        // save character 

    // save word to array of words for that letter
    addWord(key, newNode, lineNumber);



    // sort word list
    alphabeticalSort(newNode->words, newNode->wordIndex, newNode->lineNumber);

    // NO need to sort the array in create leaf function
    // sort it in the create node function

    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}


    void BSTIndexing::AddLeaf(string key, int lineNumber){
        AddLeafPrivate(key, root, lineNumber);
    }


    void BSTIndexing::AddLeafPrivate(string key, node* Ptr, int lineNumber){

        // if there is not root -> TREE DOESNT EXIST
        if (root == NULL){
            root = CreateLeaf(key, lineNumber);

        // if the first letter of the word passed is less than the first letter of the 
        // pointer passed
        } else if (key[0] < Ptr->character) {

            if (Ptr->left != NULL){
                
                AddLeafPrivate(key, Ptr->left, lineNumber);

            } else {
                Ptr->left = CreateLeaf(key, lineNumber);
            }    

        // if the first letter of the word passed is less than the first letter of the 
        // pointer passed
        } else if (key[0] > Ptr->character){

            if (Ptr->right != NULL) {

                AddLeafPrivate(key, Ptr->right, lineNumber);

            } else {
                Ptr->right = CreateLeaf(key, lineNumber);
            }

        // if key already exist add word to that letter
        } else {
            if ( Ptr->character == key[0] ){

                addWord(key, Ptr, lineNumber);
                alphabeticalSort(Ptr->words, Ptr->wordIndex, Ptr->lineNumber);

            }
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
            cout << Ptr->words[i] << "..................(" << Ptr->lineNumber[i] << ")" << endl;
        }

        cout << endl;

        if (Ptr->right != NULL){
            printInorderPrivate(Ptr->right);
        }
    } else {
        //tree empty
    }
}



void BSTIndexing::printInOrder(){
    cout << endl << endl << endl << "INDEX OF WORDS IN PAGE.TXT FILE" << endl << endl;
    printInorderPrivate(root);
}



void BSTIndexing::addAllWordsFromTextFile(string filename){
    fstream reader;
    string word;
    reader.open(filename);

    string sentence;

    int lineNumber = 0;

    while(!reader.eof()){

        getline(reader, sentence);

        stringstream iss(sentence);

        lineNumber++;
        
        while (iss >> word){
            AddLeaf(word, lineNumber);
        }
    
    }
}