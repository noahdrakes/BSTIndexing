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
    
    BSTIndexing::BSTIndexing(){
        root = NULL;
    }


    // CREATE LEAF
    //          * a leaf has no children *
    BSTIndexing::node* BSTIndexing::CreateLeaf(string key){
        node* newNode = new node;
        newNode->character = key[0];
        charactersUsed[CharactersUsedIndex] = key[0];
        CharactersUsedIndex++;

        // NO need to sort the array in create leaf function
        // sort it in the create node function
        newNode->words[newNode->wordIndex] = key;

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

            // save character 
            root->character = key[0];

            // save word to array of words for that letter
            root->words[root->wordIndex] = key;

            // sort word list
            alphabeticalSort(root->words, root->wordIndex);

        // if the first letter of the word passed is less than the first letter of the 
        // pointer passed
        } else if (key[0] < Ptr->character) {

            if (Ptr->left != NULL){
                AddLeafPrivate(key, Ptr->left);
            } else {
                Ptr->left = CreateLeaf(key);
            }
        Ptr->left->words[wordIndex] = key;
        Ptr->left->character = key[0];
        alphabeticalSort(Ptr->left->words, Ptr->left->wordIndex);

        // if the first letter of the word passed is less than the first letter of the 
        // pointer passed
        } else if (key[0] > Ptr->character){

            if (Ptr->right != NULL) {
                AddLeafPrivate(key, Ptr->right);
            } else {
                Ptr->right = CreateLeaf(key);
            }

        Ptr->right->words[wordIndex] = key;
        Ptr->right->character = key[0];
        alphabeticalSort(Ptr->right->words, Ptr->right->wordIndex);


        // if key already exist
        } else {
            cout << "key [" << key << "] has ALREADY been added to tree" << endl;
        }


    }
