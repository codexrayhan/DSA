
#include <iostream>
using namespace std;

void bubble_sort_by_absolute_value(int arr[], int n) {
    for (int i = 0; i < n -1; i++) {
        for (int j = 0; j < n - i -1; j++) {
            if (abs(arr[j]) > abs(arr[j+1])) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {-10, 5, -3, 7, -2};
    int n = 5;

    bubble_sort_by_absolute_value(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i]<<" ";


    }
    cout << endl;

    return 0;
}
