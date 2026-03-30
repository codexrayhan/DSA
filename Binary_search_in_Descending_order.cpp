
#include <iostream>
using namespace std;

int binarySearchDescending(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    int arr[] = {9, 7, 5, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = binarySearchDescending(arr, n, target);

    if (result != -1)
        cout << "Target found at index: " << result << endl;
    else
        cout << "Target not found." << endl;

    return 0;
}
