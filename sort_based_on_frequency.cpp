#include <iostream>
#include <unordered_map>
using namespace std;

void bubbleSortByFrequency(int arr[], int n, unordered_map<int,int>& freq) {
    for(int i = 0; i < n -1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(freq[arr[j]] < freq[arr[j+1]]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            else if(freq[arr[j]] == freq[arr[j+1]] && arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {4, 3, 1, 6, 1, 3, 4, 4};
    int n = 8;

    unordered_map<int,int> freq;
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    bubbleSortByFrequency(arr, n, freq);


    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

