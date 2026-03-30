
#include <iostream>
using namespace std;

void bubble_sort_by_duration(int start[], int finish[], int n) {
    for (int i = 0; i < n -1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int duration_j = finish[j] - start[j];
            int duration_j1 = finish[j+1] - start[j+1];

            if (duration_j > duration_j1) {

                int tempStart = start[j];
                start[j] = start[j+1];
                start[j+1] = tempStart;

                int tempFinish = finish[j];
                finish[j] = finish[j+1];
                finish[j+1] = tempFinish;
            }
        }
    }
}

int main() {
    int start[] = {2, 1, 4};
    int finish[] = {5, 2, 6};
    int n = 3;

    bubble_sort_by_duration(start, finish, n);


    for (int i = 0; i < n; i++) {
        cout << "(" << start[i] << ", " << finish[i] << ")";
        if (i != n - 1) cout << ", ";
    }

    return 0;
}
