
#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}


void displayList(Node* head) {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) {
        cout << "List must have at least one node." << endl;
        return 0;
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        Node* newNode = createNode(val);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }


    displayList(head);


    Node* middle = findMiddle(head);
    cout << "Middle node: " << middle->data << endl;

    return 0;
}
