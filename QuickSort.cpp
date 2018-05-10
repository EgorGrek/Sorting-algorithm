#include <ctime>
#include <iostream>
using namespace std;
void qsort(int *a, int low, int high)
{
    int i = low;
    int j = high;
    int mid = a[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (a[i] < mid)
            i++;
        while (a[j] > mid)
            j--;
        if (i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        qsort(a, low, j);
    if (i < high)
        qsort(a, i, high);
}
int main()
{
    srand(time(0));
    int size = 810000;
    int *mas = new int[size];
    for (int i = 0; i < size; i++)
        mas[i] = rand() % 100;
    int s = clock();
    qsort(mas, 0, size);
    int f = clock();
    cout << f - s << '\n';
    return 0;
}