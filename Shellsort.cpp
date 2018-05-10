#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;

void shell(int *mas, int n)
{
    int max, j;
    for (int d = n / 2; d > 0; d /= 2)
        for (int i = d; i < n; i++)
        {
            max = mas[i];
            j = i;
            while (j >= d && mas[j - d] > max)
            {
                mas[j] = mas[j - d];
                j -= d;
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
    shell(mas, size);
    int f = clock();
    cout << f - s << '\n';
    return 0;
}