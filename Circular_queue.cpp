
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int front, rear, size, capacity;

public:
    CircularQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    // Enqueue operation
    void enqueue(int val) {
        if (size == capacity) {
            cout << "Queue is full! Overwriting oldest element.\n";
            front = (front + 1) % capacity; // Circular increment
        } else {
            size++;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        cout << val << " enqueued to queue.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << arr[front] << " dequeued from queue.\n";
        front = (front + 1) % capacity;
        size--;
    }

    // Display queue elements
    void display() {
        if (size == 0) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity];
            if (i != size - 1) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    int capacity = 3;
    CircularQueue q(capacity);

    // Example operations
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40); // Overwrites oldest element (10)
    q.display();

    q.dequeue(); // Remove front (20)
    q.display();

    return 0;
}
