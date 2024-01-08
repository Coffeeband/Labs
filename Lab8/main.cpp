#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Метод Хоара (Швидке сортування)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);

        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

// Злиття впорядкованих підмасивів для методу злиття
void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1], right[n2];
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Метод злиття
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    const int size = 6;
    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 91 + 10; // генерує числа від 10 до 100
    }

    cout << "Початковий масив: ";
    printArray(arr, size);

    // Копіюємо масив для обох методів сортування
    int arr1[size];
    for (int i = 0; i < size; i++) {
        arr1[i] = arr[i];
    }

    // Сортування Хоара
    quickSort(arr, 0, size - 1);
    cout << "Відсортований масив (Хоара): ";
    printArray(arr, size);

    // Сортування злиттям
    mergeSort(arr1, 0, size - 1);
    cout << "Відсортований масив (Злиття): ";
    printArray(arr1, size);

    return 0;
}
