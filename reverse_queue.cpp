
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse a queue
void reverseQueue(queue<int> &q) {
    stack<int> s;

    // Step 1: Push all elements of queue into stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Pop from stack and push back into queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

// Function to display queue
void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front();
        q.pop();
        if (!q.empty()) cout << " -> ";
    }
    cout << endl;
}

int main() {
    queue<int> q;

    // Example Input
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Original Queue: ";
    displayQueue(q);

    reverseQueue(q);

    cout << "Reversed Queue: ";
    displayQueue(q);

    return 0;
}
