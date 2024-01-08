#include <Windows.h>
#include <iostream>
#include <cstdlib>


using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Метод бульбашки для сортування
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Метод інтерполяційного пошуку
int interpolationSearch(int arr[], int low, int high, int key) {
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == key) {
            return pos;
        }

        if (arr[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1; // Ключ не знайдений
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    const int K = 5; // Ваш номер студента
    const int N = 20 + 0.6 * K;

    int arr[N];

    // Заповнення масиву випадковими числами
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 91 + 10; // генерує числа від 10 до 100
    }

    cout << "Початковий масив: ";
    printArray(arr, N);

    // Сортування методом бульбашки
    bubbleSort(arr, N);

    cout << "Відсортований масив: ";
    printArray(arr, N);

    // Знаходження ключа в середині лівої частини масиву за інтерполяційним пошуком
    int leftMiddleKey = arr[N / 4];
    cout << "Ключ, що знаходиться в середині лівої частини масиву: " << leftMiddleKey << endl;

    int result = interpolationSearch(arr, 0, N - 1, leftMiddleKey);

    if (result != -1) {
        cout << "Ключ знайдений на позиції " << result << endl;
    } else {
        cout << "Ключ не знайдений" << endl;
    }

    return 0;
}

