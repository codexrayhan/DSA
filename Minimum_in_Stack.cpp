
#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<int> mainStack;
    stack<int> minStack;

public:
    // Push element into stack
    void push(int x) {
        mainStack.push(x);
        // If minStack is empty or new element is smaller, push it to minStack
        if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
    }

    // Pop element from stack
    void pop() {
        if (mainStack.empty()) return;
        if (mainStack.top() == minStack.top())
            minStack.pop();
        mainStack.pop();
    }

    // Get top element
    int top() {
        if (mainStack.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return mainStack.top();
    }

    // Get minimum element in constant time
    int getMin() {
        if (minStack.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return minStack.top();
    }
};

int main() {
    MinStack st;
    st.push(10);
    st.push(20);
    st.push(5);

    cout << "Minimum Element: " << st.getMin() << endl;

    return 0;
}
