
#include <iostream>
#include <stack>
#include <stdexcept>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> s1, s2;

    void transfer() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    void enqueue(int x) {
        s1.push(x);
        cout << x << " enqueued to queue.\n";
    }

    void dequeue() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is empty!\n";
                return;
            }
            transfer();
        }
        cout << s2.top() << " dequeued from queue.\n";
        s2.pop();
    }

    int front() {
        if (s2.empty()) {
            if (s1.empty()) throw runtime_error("Queue is empty!");
            transfer();
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    QueueUsingStacks q;
    int choice, val;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Front\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                try { cout << "Front of Queue: " << q.front() << endl; }
                catch (runtime_error &e) { cout << e.what() << endl; }
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
