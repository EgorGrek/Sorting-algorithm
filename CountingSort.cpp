#include <ctime>
#include <iostream>
using namespace std;

void countsort(int *mas, int size)
{
    int *hell = new int[size];
    int C[100] = {0};

    for (int i = 0; i < size; i++)
        C[mas[i]]++;

    for (int i = 1; i < 100; i++)
        C[i] += C[i - 1];

    for (int i = 0; i < size; i++)
    {
        hell[C[mas[i]] - 1] = mas[i];
        C[mas[i]]--;
    }
    for (int i = 0; i < size; i++)
        mas[i] = hell[i];
}

int main()
{
    srand(time(0));
    int size = 810000;
    int *mas = new int[size];
    for (int i = 0; i < size; i++)
        mas[i] = rand() % 100;
    int s = clock();
    countsort(mas, size);
    int f = clock();
    cout << f - s << '\n';
    return 0;
}