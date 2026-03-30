
#include <iostream>
#include <queue>
using namespace std;

void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1"); // Start with "1"

    cout << "Binary Numbers: ";
    for (int i = 0; i < n; i++) {
        string s = q.front();
        q.pop();
        cout << s;
        if (i != n - 1) cout << ", ";

        // Append "0" and "1" and push back to queue
        q.push(s + "0");
        q.push(s + "1");
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    generateBinaryNumbers(n);

    return 0;
}
