
#include <bits/stdc++.h>
using namespace std;

// Function to sort a stack using one auxiliary stack
stack<int> sortStack(stack<int> &inputStack) {
    stack<int> tempStack;

    while (!inputStack.empty()) {
        int temp = inputStack.top();
        inputStack.pop();

        // Move elements from tempStack back to inputStack
        // until we find the right place for temp
        while (!tempStack.empty() && tempStack.top() > temp) {
            inputStack.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }

    return tempStack; // tempStack contains sorted elements
}

void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top();
        st.pop();
        if (!st.empty()) cout << " -> ";
    }
    cout << endl;
}

int main() {
    stack<int> st;
    st.push(30);
    st.push(10);
    st.push(20);
    st.push(50);
    st.push(40);

    cout << "Original Stack: 30 -> 10 -> 20 -> 50 -> 40" << endl;

    stack<int> sortedStack = sortStack(st);

    cout << "Sorted Stack: ";
    printStack(sortedStack);

    return 0;
}
