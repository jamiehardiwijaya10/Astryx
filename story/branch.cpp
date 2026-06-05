#include <iostream>
#include <string>
using namespace std;

struct StoryNode{
    int id;
    StoryNode* left;
    StoryNode* right;
};

StoryNode* createScene(int id){
    StoryNode* node = new StoryNode;
    node->id = id;
    node->left = NULL;
    node->right = NULL;
    return node;
}

StoryNode* buildTree(){

    StoryNode* root = createScene(0);

    root->left = createScene(1); 
    root->right = createScene(2);

    return root;
}

int choosePath(){

    while (true) {
        StoryNode* tree = buildTree();

        int pilih;

        cout << "\nChoice:\n";
        cout << "1. Pursue the researcher immediately\n";
        cout << "2. Stay in Rovenila and prepare an expedition first\n";
        cout << "Choose : ";
        cin >> pilih;
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            continue;
        }
        if(pilih == 1){
            return tree->left->id;

        return tree->right->id;
        }
        else {
            cout << "Invalid choice!" << endl;
            continue;
        }
    }
}