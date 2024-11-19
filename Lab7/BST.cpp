#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;

class BST {
private:
    vector<int> tree;  // Dynamic array to store the tree elements

    // Helper function to find the left child index
    int leftChild(int i) {
        return 2 * i + 1;
    }

    // Helper function to find the right child index
    int rightChild(int i) {
        return 2 * i + 2;
    }

    // Helper function to insert a value into the BST at the correct position
    void insertHelper(int index, int value) {
        // Check if the current index is within the bounds of the tree array
        if (index >= tree.size()) {
            tree.resize(index + 1, -1);  // Resize and initialize new elements as -1 (empty)
        }

        if (tree[index] == -1) {  // Empty space found, insert the value
            tree[index] = value;
        } else {
            // Move to the left or right child depending on the value
            if (value < tree[index]) {
                insertHelper(leftChild(index), value);  // Go left
            } else if (value > tree[index]) {
                insertHelper(rightChild(index), value);  // Go right
            }
        }
    }

    // Helper function for inorder traversal
    void inorderHelper(int index) {
        if (index >= tree.size() || tree[index] == -1) {
            return;  // Exit if index is out of bounds or empty
        }
        
        inorderHelper(leftChild(index));  // Traverse left subtree
        cout << tree[index] << " ";  // Visit the node
        inorderHelper(rightChild(index));  // Traverse right subtree
    }

public:
    // Constructor initializes an empty tree with a root of -1 (indicating empty)
    BST() {
        tree.push_back(-1);  // The root is initially empty (index 0)
    }

    // Insert a value into the BST
    void insert(int value) {
        insertHelper(0, value);  // Start insertion from the root (index 0)
    }

    // Inorder traversal of the tree
    void inorder() {
        inorderHelper(0);  // Start traversal from the root (index 0)
        cout << endl;
    }

    // Search for a value in the tree
    bool search(int value) {
        int i = 0;
        while (i < tree.size() && tree[i] != -1) {
            if (tree[i] == value) {
                return true;
            } else if (value < tree[i]) {
                i = leftChild(i);  // Move to the left child
            } else {
                i = rightChild(i);  // Move to the right child
            }
        }
        return false;  // Value not found or reached an empty space
    }
    
    // Method to find the minimum value in the tree
    int findMin() {
        int index = 0;
        // Traverse left until we find the leftmost node
        while (index < tree.size() && tree[index] != -1) {
            int left = leftChild(index);
            // If the left child exists, move to it
            if (left < tree.size() && tree[left] != -1) {
                index = left;
            } else {
                break;  // No more left children, this is the minimum
            }
        }
        // Return the minimum value, or -1 if the tree is empty
        return (index < tree.size() && tree[index] != -1) ? tree[index] : -1;
    }
    
    // Method to find the maximum value in the tree
    int findMax() {
        int index = 0;
        // Traverse right until we find the rightmost node
        while (index < tree.size() && tree[index] != -1) {
            int right = rightChild(index);
            // If the right child exists, move to it
            if (right < tree.size() && tree[right] != -1) {
                index = right;
            } else {
                break;  // No more right children, this is the maximum
            }
        }
        // Return the maximum value, or -1 if the tree is empty
        return (index < tree.size() && tree[index] != -1) ? tree[index] : -1;
    }

    // Preorder Traversal: Node -> Left -> Right
    void preorderHelper(int index) {
        if (index >= tree.size() || tree[index] == -1) {
            return;
        }
    
        // Visit the current node
        cout << tree[index] << " ";
    
        // Traverse the left subtree
        preorderHelper(leftChild(index));
    
        // Traverse the right subtree
        preorderHelper(rightChild(index));
    }
    
    // Public method to start preorder traversal from the root
    void preorder() {
        preorderHelper(0);  // Start from the root (index 0)
        cout << endl;
    }
    
    // Postorder Traversal: Left -> Right -> Node
    void postorderHelper(int index) {
        if (index >= tree.size() || tree[index] == -1) {
            return;  // If the index is out of bounds or the node is empty, return
        }
    
        // Traverse the left subtree
        postorderHelper(leftChild(index));
    
        // Traverse the right subtree
        postorderHelper(rightChild(index));
    
        // Visit the current node
        cout << tree[index] << " ";
    }
    
    // Public method to start postorder traversal from the root
    void postorder() {
        postorderHelper(0);  // Start from the root (index 0)
        cout << endl;
    }
    
    void preorderHelper(int index, int depth) {
        if (index >= tree.size() || tree[index] == -1) {
            return;  // If the node is out of bounds or empty, return
        }

        // Print the current node with indentation based on depth
        cout << string(depth * 4, ' ') << tree[index] << endl;

        // Recursively print the left and right subtrees
        preorderHelper(leftChild(index), depth + 1);
        preorderHelper(rightChild(index), depth + 1);
    }

    // Wrapper for the public method to print the tree using preorder traversal
    void visualizeTree() {
        preorderHelper(0, 0);  // Start from the root (index 0) with depth 0
    }
};

// Main function to test the Binary Search Tree
int main() {
    BST tree;

    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(50);

    cout << "Inorder Traversal: ";
    tree.inorder();
    cout << "Preorder Traversal: ";
    tree.preorder();
    cout << "Postorder Traversal: ";
    tree.postorder();

    cout << "Search for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search for 25: " << (tree.search(25) ? "Found" : "Not Found") << endl;
    cout << "Max = " << tree.findMax() << endl;
    cout << "Min = " << tree.findMin() << endl;
    
    tree.visualizeTree();

    return 0;
}
