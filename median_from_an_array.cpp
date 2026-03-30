
#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
double find_median(int arr[], int n) {
    bubble_sort(arr, n);
    if (n % 2 != 0)
        return arr[n / 2];
    else
        return (arr[(n - 1) / 2] + arr[n / 2]) / 2;
}
int main() {
    int arr1[] = {5, 2, 1, 4, 7};
    int n1 = 5;
    cout << find_median(arr1, n1) <<endl;

    int arr2[] = {11, 9, 17, 15};
    int n2 = 4;
    cout << find_median(arr2, n2) << endl;

    return 0;
}
