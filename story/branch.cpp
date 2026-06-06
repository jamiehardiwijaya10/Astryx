#include <iostream>
using namespace std;

struct StoryNode{
    int scene;
    StoryNode* left;
    StoryNode* right;
};

StoryNode* createScene(int scene){
    StoryNode* node = new StoryNode;
    node->scene = scene;
    node->left = NULL;
    node->right = NULL;
    return node;
}

StoryNode* buildTree(){

    StoryNode* root = createScene(14);

    root->left = createScene(15);
    root->right = createScene(17);

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

        if(cin.fail()){
            cin.clear();
            cin.ignore();
            continue;
        }

        if(pilih == 1){
            return tree->left->scene;
        }

        if(pilih == 2){
            return tree->right->scene;
        }
        else{
            cout << "Invalid choice!\n";
        }
    }
}