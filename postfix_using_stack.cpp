
#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(string expr) {
    stack<int> st;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        // If token is an operator
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (st.size() < 2) {
                cout << "Invalid expression!" << endl;
                return 0;
            }
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b); // integer division
        }
        else { // token is a number
            st.push(stoi(token));
        }
    }

    if (st.size() != 1) {
        cout << "Invalid expression!" << endl;
        return 0;
    }

    return st.top();
}

int main() {
    string expr = "5 1 2 + 4 * + 3 -";
    cout << "Postfix Expression: " << expr << endl;

    int result = evaluatePostfix(expr);
    cout << "Evaluated Result: " << result << endl;

    return 0;
}
