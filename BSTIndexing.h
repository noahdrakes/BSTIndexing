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
        };

        node* root;

        char charactersUsed[26];

    public:

        BSTIndexing();
        node* CreateLeaf(string key);
        void addUsedCharacterToArray(char input);

};