
#include <iostream>
using namespace std;


int findPeakElement(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1]) {

            low = mid + 1;
        } else {

            high = mid;
        }
    }
    return low;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int peakIndex = findPeakElement(arr, n);

    cout << "Peak element is " << arr[peakIndex]
         << " at index " << peakIndex << endl;

    return 0;
}
