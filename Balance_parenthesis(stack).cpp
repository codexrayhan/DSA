#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string expression) {
    stack<char> st;

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.empty()) return false; // no opening bracket

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return st.empty(); // true if no unmatched opening bracket remains
}

int main() {
    string str = "(a+b)*(c+d)";
    cout << "String: " << str << endl;

    if (isBalanced(str))
        cout << "Balanced: Yes" << endl;
    else
        cout << "Balanced: No" << endl;

    return 0;
}
