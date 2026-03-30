
#include <iostream>
#include <queue>
#include <stdexcept>
using namespace std;

class StackUsingQueues {
private:
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        cout << x << " pushed to stack.\n";
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << q1.front() << " popped from stack.\n";
        q1.pop();
    }

    int top() {
        if (q1.empty()) throw runtime_error("Stack is empty!");
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackUsingQueues s;
    int choice, val;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push\n2. Pop\n3. Top\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                try { cout << "Top of Stack: " << s.top() << endl; }
                catch (runtime_error &e) { cout << e.what() << endl; }
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
