#include <ctime>
#include <iostream>
using namespace std;

void countSort(int *arr, int n, int exp)
{
    int *output = new int[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix(int *arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];

    for (int t = 1; mx / t > 0; t *= 10)
        countSort(arr, n, t);
}

int main()
{
    srand(time(0));
    int size = 810000;
    int *mas = new int[size];
    for (int i = 0; i < size; i++)
        mas[i] = rand() % 100;
    int s = clock();
    radix(mas, size);
    int f = clock();
    cout << f - s << '\n';
    return 0;
}