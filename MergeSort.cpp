#include <ctime>
#include <iostream>
using namespace std;

void merge(int *mas, int begin, int end)
{
    if (begin == end - 1)
        return;

    int s = (begin + end) / 2;
    merge(mas, begin, s);
    merge(mas, s, end);

    int *temp = new int[end - begin];
    int c = 0;
    int i = begin;
    int j = s;
    while (true)
    {
        if (j >= end && i >= s)
            break;
        else if (j >= end)
        {
            while (i < s)
            {
                temp[c] = mas[i];
                i++;
                c++;
            }
            break;
        }
        else if (i >= s)
        {
            while (j < end)
            {
                temp[c] = mas[j];
                j++;
                c++;
            }
            break;
        }
        else if (mas[i] >= mas[j])
        {
            temp[c] = mas[j];
            j++;
            c++;
        }
        else
        {
            temp[c] = mas[i];
            i++;
            c++;
        }
    }

    for (i = begin, j = 0; i < end, j < c; i++, j++)
        mas[i] = temp[j];
}
int main()
{
    srand(time(0));
    int size = 810000;
    int *mas = new int[size];
    for (int i = 0; i < size; i++)
        mas[i] = rand() % 100;
    int s = clock();
    merge(mas, 0, size);
    int f = clock();
    cout << f - s << '\n';

    for (int i = 0; i < size; i++)
        cout << mas[i] << ' ';
    return 0;
}