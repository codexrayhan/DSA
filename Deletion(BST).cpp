
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    // Recursive insertion
    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);

        return node;
    }

    // Find minimum node (used in deletion)
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // Recursive deletion
    Node* deleteNode(Node* node, int val) {
        if (node == nullptr)
            return node;

        // Traverse to find the node
        if (val < node->data)
            node->left = deleteNode(node->left, val);
        else if (val > node->data)
            node->right = deleteNode(node->right, val);
        else {
            // Case 1: No child (leaf node)
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            // Case 2: One child
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Two children
            else {
                Node* temp = findMin(node->right);
                node->data = temp->data; // Replace value
                node->right = deleteNode(node->right, temp->data); // Delete successor
            }
        }
        return node;
    }

    // Inorder traversal
    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data;
        if (node != findMax(root)) cout << " → ";
        inorder(node->right);
    }

    Node* findMax(Node* node) {
        while (node && node->right != nullptr)
            node = node->right;
        return node;
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void deleteNode(int val) {
        root = deleteNode(root, val);
    }

    void displayInorder() {
        cout << "Inorder Traversal after Deletion: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int elements[] = {50, 30, 70, 20, 40, 60, 80};

    // Insert elements
    for (int val : elements)
        tree.insert(val);

    // Delete node
    tree.deleteNode(70);

    // Display inorder traversal after deletion
    tree.displayInorder();

    return 0;
}
