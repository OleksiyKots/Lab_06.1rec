#include <iostream>
#include <iomanip>

using namespace std;

void create(int* arr, int SIZE, int MIN, int MAX, int i)
{
    if (i < SIZE)
    {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
        create(arr, SIZE, MIN, MAX, ++i);
    }
}

void Print(int* arr, const int SIZE, int i)
{
    cout << setw(4) << arr[i];
    if (i < SIZE - 1)
        Print(arr, SIZE, i + 1);
    else
        cout << endl;
}

int Sum(int* arr, int SIZE, int sum, int i)
{
    if (i < SIZE)
    {
        if (arr[i] < 0 && arr[i] % 2 == 0)
            sum += arr[i];

        Sum(arr, SIZE, sum, ++i);
    }
    else return sum;
}

int Count(int* arr, int SIZE, int count, int i)
{
    if (i < SIZE)
    {
        if (arr[i] < 0 && arr[i] % 2 == 0)
            count++;

        Count(arr, SIZE, count, ++i);
    }
    else return count;
}

void updateArray(int* arr, int SIZE, int i)
{
    if (i < SIZE)
    {
        if (arr[i] < 0 && arr[i] % 2 == 0)
        {
            arr[i] = 0;
        }
        updateArray(arr, SIZE, ++i);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    const int SIZE = 20;
    int arr[SIZE];
    create(arr, SIZE, -20, 34, 0);
    Print(arr, SIZE, 0);
    cout << endl;
    cout << "sum = " << Sum(arr, SIZE, 0, 0) << endl;
    cout << "count = " << Count(arr, SIZE, 0, 0) << endl;
    updateArray(arr, SIZE, 0);
    Print(arr, SIZE, 0);
    cout << endl;
    return 0;
}
