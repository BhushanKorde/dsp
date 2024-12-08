#include <iostream>
using namespace std;

int main() {
    int first, last, count = 0;
    int A[20];
    int flag = 1;
    int N, i, j, Target;

    cout << "Enter the Size of Your Array: ";
    cin >> N;

    for (i = 0; i < N; i++) {
        cout << "Enter the " << i + 1 << " Element: ";
        cin >> A[i];
    }

    cout << "Your Array is:\n";
    for (i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Bubble sort
    for (i = 0; i < N; i++) {
        for (j = 0; j < N - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    // Display sorted array
    cout << "\nYour Sorted Array is:\n";
    for (i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Search for the target
    cout << "\nEnter the Target you want to search: ";
    cin >> Target;

    for (i = 0; i < N; i++) {
        if (A[i] == Target) {
            if (count == 0) {
                cout << "First Target Found at Index " << i << endl;
            }
            count++;
            flag = 0;
        } else if (count > 0 && flag == 0) {
            cout << "Last Target is at Index " << i - 1 << endl;
            break;
        }
    }

    if (flag == 1) {
        cout << "Target Not Found" << endl;
    }

    return 0;
}
