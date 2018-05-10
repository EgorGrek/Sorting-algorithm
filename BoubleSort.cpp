#include <ctime>
#include <iostream>
using namespace std;

void bouble(int *mas, int begin, int end)
{
    for (int i = begin; i < end; i++)
        for (int j = begin; j < end - 1 - i; j++)
            if (mas[j] > mas[j + 1])
            {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
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
    bouble(mas, 0, size);
    int f = clock();
    cout << f - s << '\n';
    return 0;
}