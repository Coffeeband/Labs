#include <iostream>
#include <cstdlib>
#include <ctime>
const int arraySize = 5;


using namespace std;
void Array(int A[]) {
    srand(time(0));
    for (int i = 0; i < arraySize; ++i) {
        A[i] = rand() % 91 + 10;
    }
}

void printArray(int A[]) {
    for (int i = 0; i < arraySize; ++i) {
        std::cout << A[i] << " ";
    }
    cout << std::endl;
}


void SortofBubble(int A[]) {
    for (int i = 0; i < arraySize - 1; ++i) {
        for (int j = 0; j < arraySize - i - 1; ++j) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void SortOfinsertion(int A[]) {
    for (int i = 1; i < arraySize; ++i) {
        int key = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key;
    }
}

int main() {
    int A[arraySize];

    cout << "Початковий масив: ";
    Array(A);
    printArray(A);

    cout << "Масив після сортування бульбашкою: ";
    SortofBubble(A);
    printArray(A);

    Array(A);
    cout << "Початковий масив: ";
    printArray(A);

    cout << "Масив після сортування методом вставки: ";
    SortOfinsertion(A);
    printArray(A);

    return 0;
}

