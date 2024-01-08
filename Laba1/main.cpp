#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
void number1() {
    int arr[14];
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < 14; i++)
    {
        arr[i] = getRandomNumber(-20, 20);
        cout << arr[i] << " ";
    }
    int sumPositives = 0;
    int sumNegatives = 0;
    int countNegatives = 0;
    for (int i = 0; i < 14; i++) {
        if (arr[i] > 0) {
            sumPositives += arr[i];
        }
        else if (arr[i] < 0) {
            sumNegatives += arr[i];
            countNegatives++;
        }
    }
    cout<<endl;
    cout << "Сума додатніх чисел: " << sumPositives << endl;
    cout << "Сума від'ємних чисел: " << sumNegatives << endl;
    cout << "К-сть від'ємних чисел: " << countNegatives << endl;
}
void number2()
{
    int arr[6][4];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j] = getRandomNumber(-20, 20);
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }

    int sumPositives = 0;
    int countPositives = 0;
    int avgPositive = 1.0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
                if (arr[j][i] > 0) {
            sumPositives += arr[j][i];
            countPositives++;
        }
        }
if (countPositives >= 0) {
        avgPositive = sumPositives / countPositives;
            }
        cout << "Середнє арефметичне додатніх елементів рядка: " << avgPositive << endl;
        avgPositive= 0;
        sumPositives = 0;
        countPositives = 0;
    }
}
int main()
{
    cout << "1): " << endl;
    cout << endl;
    number1();
    cout << endl;
    cout << "2): " << endl;
    cout << endl;
    number2();
    return 0;
}
