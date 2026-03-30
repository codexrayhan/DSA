#include <iostream>
using namespace std;

int integerSqrt(int x) {
    if (x < 2) return x;

    int low = 1, high = x / 2, ans = 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int square = mid * mid;

        if (square == x) {
        }
        else if (square < x) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int x;
    cout << "Enter a non-negative integer: ";
    cin >> x;

    int result = integerSqrt(x);
    cout << result << endl;

    return 0;
}

