#include <string>

using namespace std;
class BSTIndexing{
    private:


        int CharactersUsedIndex = 0;

        struct node{
            char character;
            string words[1000];
            node* left;
            node* right;
            int wordIndex = 0;
        };

        node* root;

        char charactersUsed[26];

        void AddLeafPrivate(string key, node* Ptr);
        void addWordPrivate(string key, node* Ptr);
    public:
        
        BSTIndexing();
        node* CreateLeaf(string key);
        void AddLeaf(string key);
        void addWord(string key, node* Ptr);
        int returnWordArrayLength();
        string returnWord(int index);


};


void alphabeticalSort(string array[], int arraySize);
    