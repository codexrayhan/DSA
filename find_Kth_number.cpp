
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main() {
    int a1[] = {6, 5, 1, 3, 4};
    int k = 2;
    int n = 5;

    bubbleSort(a1, n);
    cout << "Output 1: " << a1[k-1] << endl;

    int a2[] = {7, 9, 1, 8, 2};
    k = 4;
    n = 5;

    bubbleSort(a2, n);
    cout << "Output 2: " << a2[k-1] << endl;

    return 0;
}
