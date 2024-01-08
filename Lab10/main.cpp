#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;
int directSearch(const string& S, const string& P) {

    int n = S.length();
    int m = P.length();

    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && S[i + j] == P[j]) {
            ++j;
        }

        if (j == m) {
            return i; // Знайдено входження
        }
    }

    return -1; // Не знайдено входження
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    string S = "мамаміякергуду";
    string P = "мія";

    cout << "Масив S: " << S << endl;
    cout << "Масив P: " << P << endl;

    int result = directSearch(S, P);

    if (result != -1) {
        cout << "Перше входження P у S починається з позиції " << result << endl;
    } else {
        cout << "P не знайдено у S" << endl;
    }

    return 0;
}

