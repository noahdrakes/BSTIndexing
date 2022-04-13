#include <string>
#include <fstream>

using namespace std;
class BSTIndexing{
    private:


        int CharactersUsedIndex = 0;

        struct node{
            char character;
            node* left;
            node* right;

            string words[1000];
            int wordIndex = 0;

            int lineNumber[1000];
            int lineNumberIndex = 0;
        };

        node* root;

        char charactersUsed[26];

        void AddLeafPrivate(string key, node* Ptr, int lineNumber);
        void addWordPrivate(string key, node* Ptr, int lineNumber);
        void printInorderPrivate(node* Ptr);

    public:
        
        BSTIndexing();
        node* CreateLeaf(string key, int lineNumber);
        void AddLeaf(string key, int lineNumber);
        void addWord(string key, node* Ptr, int lineNumber);
        
        int returnWordArrayLength();
        string returnWord(int index);
        void printInOrder();
        void addAllWordsFromTextFile(string filename);


};


void alphabeticalSort(string array[], int arraySize, int lineNumberArray[]);
    