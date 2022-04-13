#include <string>

using namespace std;
class BSTIndexing{
    private:

        int wordIndex = 0;
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

    public:
        
        BSTIndexing();
        node* CreateLeaf(string key);
        void AddLeaf(string key);


};


void alphabeticalSort(string array[], int arraySize);
    