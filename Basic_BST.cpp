
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


    bool search(Node* node, int val) {
        if (node == nullptr)
            return false;
        if (node->data == val)
            return true;
        else if (val < node->data)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    bool search(int val) {
        return search(root, val);
    }
};

int main() {
    BST tree;
    int elements[] = {50, 30, 70, 20, 40, 60, 80};

    for (int val : elements)
        tree.insert(val);


    int searchValues[] = {40, 90};

    cout << "Search Result:\n";
    for (int val : searchValues) {
        if (tree.search(val))
            cout << val << ": Found\n";
        else
            cout << val << ": Not Found\n";
    }

    return 0;
}
