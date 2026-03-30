
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

    Node* insert(Node* node, int val) {
        if (node == nullptr)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);

        return node;
    }

    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == nullptr)
            return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

  public:
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    void displayInorder() {
        cout << "In order Traversal: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Pre order Traversal: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Post order Traversal: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int elements[] = {50, 30, 70, 20, 40, 60, 10};

    for (int val : elements)
        tree.insert(val);

    tree.displayInorder();
    tree.displayPreorder();
    tree.displayPostorder();

    return 0;
}

