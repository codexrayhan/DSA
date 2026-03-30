#include <iostream>
using namespace std;

void bubbleSortEvenAscending(int arr[], int n) {
    for (int i = 0; i < n - 1; i += 2) {
        for (int j = 0; j < n -1; j += 2) {
            if (arr[j] > arr[j + 2]) {
                int temp = arr[j];
                arr[j] = arr[j + 2];
                arr[j + 2] = temp;
            }
        }
    }
}

void bubbleSortOddDescending(int arr[], int n) {
    for (int i = 1; i < n - 1; i += 2) {
        for (int j = 1; j < n -1; j += 2) {
            if (arr[j] < arr[j + 2]) {
                int temp = arr[j];
                arr[j] = arr[j + 2];
                arr[j + 2] = temp;
            }
        }
    }
}

int main() {
    int arr1[] = {16,17,4,18,1,20,5,12};
    int n1 = 8;

    bubbleSortEvenAscending(arr1, n1);
    bubbleSortOddDescending(arr1, n1);

    for (int i = 0; i < n1; i++) {
        cout << arr1[i];
        cout<< " ";
    }

    return 0;
}
