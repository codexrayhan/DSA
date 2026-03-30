
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
        else if (val > node->data)
            node->right = insert(node->right, val);

        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
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

    int getMin() {
        Node* minNode = findMin(root);
        if (minNode)
            return minNode->data;
        throw runtime_error("Tree is empty!");
    }

    int getMax() {
        Node* maxNode = findMax(root);
        if (maxNode)
            return maxNode->data;
        throw runtime_error("Tree is empty!");
    }
};

int main() {
    BST tree;
    int elements[] = {50, 30, 70, 20, 40, 60, 80};


    for (int val : elements)
        tree.insert(val);

    cout << "Minimum Value: " << tree.getMin() << endl;
    cout << "Maximum Value: " << tree.getMax() << endl;

    return 0;
}
