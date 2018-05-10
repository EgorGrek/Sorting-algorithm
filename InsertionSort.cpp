#include <ctime>
#include <iostream>
using namespace std;

void insertion(int *mas, int size)
{
    int j, i, max;
    for (i = 1; i < size; i++)
    {
        max = mas[i];
        j = i;
        while (j >= 1 && mas[j - 1] > max)
        {
            mas[j] = mas[j - 1];
            j--;
        }
        mas[j] = max;
    }
}

int main()
{
    srand(time(0));
    int size = 810000;
    int *mas = new int[size];
    for (int i = 0; i < size; i++)
        mas[i] = rand() % 100;
    int s = clock();
    insertion(mas, size);
    int f = clock();
    cout << f - s << '\n';
    return 0;
}