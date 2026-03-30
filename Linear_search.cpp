
#include <iostream>
using namespace std;


int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {5, 3, 8, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    int result = linearSearch(arr, n, target);

    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found." << endl;

    return 0;
}
