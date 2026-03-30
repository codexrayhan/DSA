
#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n) {
    for(int i = 0; i < n -1; i++) {
        for(int j = 0; j < n - i -1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int longest_consecutive_subsequence(int arr[], int n) {
    if (n == 0) return 0;

   bubble_sort(arr, n);

    int maxLen = 1;
    int currentLen = 1;

    for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i-1])
            continue;

        if(arr[i] == arr[i-1] + 1) {
            currentLen++;
        } else {
            currentLen = 1;
        }

        if(currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen;
}

int main() {
    int arr1[] = {1, 9, 3, 10, 4, 20, 2};
    int n1 = 7;
    cout << longest_consecutive_subsequence(arr1, n1) << endl;


    return 0;
}
