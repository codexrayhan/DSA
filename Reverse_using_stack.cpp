
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    stack<char> s;

    for (char ch : input)
    {
        s.push(ch);
    }

    string reversed = "";// an empty string to store reverse
    while (!s.empty())
    {
        reversed += s.top();
        s.pop();
    }

    cout << "Reversed String: \"" << reversed << "\"" << endl;

    return 0;
}


