
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str) {
    stack<char> st;

    // Push all characters into the stack
    for (char ch : str) {
        st.push(ch);
    }

    // Pop characters from the stack to get reversed string
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }

    return reversed;
}

int main() {
    string str = "HELLO";
    cout << "Original String: " << str << endl;

    string reversedStr = reverseString(str);
    cout << "Reversed String: " << reversedStr << endl;

    return 0;
}
