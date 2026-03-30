
#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n -1; i++) {
        for (int j = 0; j < n - i -1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int smallest_difference(int arr[], int n) {
    int min_diff =99999;
    for (int i = 1; i < n; i++) {
        int diff = arr[i] - arr[i-1];
        if (diff < min_diff)
            min_diff = diff;


    }
    return min_diff;
}

int biggest_difference(int arr[], int n) {
    return arr[n-1] - arr[0];
}

int main() {
    int arr1[] = {15,7,2,12,13};
    int n1 = 5;
    bubble_sort(arr1, n1);
    cout << "Smallest difference: " << smallest_difference(arr1, n1) << endl;
    cout << "Biggest difference: " << biggest_difference(arr1, n1) << endl;

    int arr2[] = {2,13,11,19,5};
    int n2 = 5;
    bubble_sort(arr2, n2);
    cout << "Smallest difference: " << smallest_difference(arr2, n2) << endl;
    cout << "Biggest difference: " << biggest_difference(arr2, n2) << endl;

    return 0;
}
