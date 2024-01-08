#include <iostream>
#include <cstdlib>

using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void shellSort(int arr[], int n) {

    for (int g = n / 2; g > 0; g /= 2) {

        for (int i = g; i < n; i++) {
            int temp = arr[i];

            for (int j = i; j >= g && arr[j - g] > temp; j -= g) {
                arr[j] = arr[j - g];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    const int size = 6;
    int arr[size];


    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 91 + 10;
    }

    cout << "Початковий масив: ";
    printArray(arr, size);


    shellSort(arr, size);

    cout << "Відсортований масив: ";
    printArray(arr, size);

    return 0;
}
