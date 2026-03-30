
#include <iostream>
using namespace std;

void bubble_sort_by_length(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].length() > arr[j + 1].length()) {

                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    string arr[] = {"apple", "bat", "carrot", "dog"};
    int n = 4;

bubble_sort_by_length(arr, n);


    for (int i = 0; i < n; i++) {
        cout << "\"" << arr[i] << "\"";
        if (i != n - 1)
        cout << ", ";

    }
    cout << endl;

    return 0;
}
