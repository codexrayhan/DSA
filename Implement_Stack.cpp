#include <iostream>
using namespace std;

#define MAX 100  // Maximum size of the stack

class Stack {
    int arr[MAX];
    int topIndex;

public:
    Stack() { topIndex = -1; } // Constructor initializes topIndex

    // Check if stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Push element into stack
    void push(int x) {
        if (topIndex >= MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++topIndex] = x;
    }

    // Pop element from stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        topIndex--;
    }

    // Get the top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    // Print stack elements
    void printStack() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = 0; i <= topIndex; i++) {
            cout << arr[i];
            if (i != topIndex) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    Stack st;

    // Example operations
    st.push(10);
    st.push(20);
    st.push(30);
    st.pop();

    cout << "Stack: ";
    st.printStack();

    return 0;
}
