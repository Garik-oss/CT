#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    int level;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x, int lvl) : val(x), level(lvl), left(NULL), right(NULL) {}
};

// Helper function to print the tree with lines
void printTreeHelper(TreeNode* node, int space = 0, int level = 0) {
    if (node == NULL) {
        return;
    }

    // Increase space for the next level
    space += 5;

    // First print right child
    printTreeHelper(node->right, space, level + 1);

    // Print current node after space
    cout << endl;
    for (int i = 5; i < space; i++) {
        cout << " ";
    }
    cout << node->val << endl;

    // Then print left child
    printTreeHelper(node->left, space, level + 1);
}

int main() {
    TreeNode* root = new TreeNode(1, 0);  // Root node at level 0
    root->left = new TreeNode(2, 1);      // Left child at level 1
    root->right = new TreeNode(3, 1);     // Right child at level 1
    root->left->left = new TreeNode(4, 2); // Left-left child at level 2
    root->left->right = new TreeNode(5, 2); // Left-right child at level 2
    root->right->left = new TreeNode(6, 2); // Right-left child at level 2
    root->right->right = new TreeNode(7, 2); // Right-right child at level 2

    // Print the tree in a more "beautiful" format
    printTreeHelper(root);

    return 0;
}
