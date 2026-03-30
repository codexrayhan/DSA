
#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n -1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int a[] = {1, 16, 13, 14, 4};
    int b[] = {15, 12, 5, 3, 7};

    int n1 = 5;
    int n2 = 5;

    int merged[10];

    for (int i = 0; i < n1; i++) {
        merged[i] = a[i];
    }

    for (int i = 0; i < n2; i++) {
        merged[n1 + i] = b[i];
    }

    int totalSize = n1 + n2;

    bubble_sort(merged, totalSize);


    for (int i = 0; i <10; i++) {
        cout << merged[i];
        if (i !=10 - 1) cout << ", ";
    }


    return 0;
}
