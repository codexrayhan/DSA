
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int> &q, int k) {
    if (q.empty() || k <= 0 || k > q.size()) return;

    stack<int> st;

    // Step 1: Push first k elements into a stack
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue back the elements from stack (reversed order)
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move the remaining elements to the back to maintain order
    int t = q.size() - k;
    for (int i = 0; i < t; i++) {
        q.push(q.front());
        q.pop();
    }
}

void printQueue(queue<int> q) {
    cout << "[";
    while (!q.empty()) {
        cout << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 3;

    cout << "Original Queue: ";
    printQueue(q);

    reverseFirstK(q, k);

    cout << "Modified Queue: ";
    printQueue(q);

    return 0;
}
