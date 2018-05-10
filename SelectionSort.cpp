#include <ctime>
#include <iostream>
using namespace std;
void selection(int *mas, int size)
{
    while (size > 1)
    {
        int ind = 0;
        int mx = mas[0];
        for (int i = 1; i < size; i++)
            if (mas[i] > mx)
            {
                mx = mas[i];
                ind = i;
            }
        mas[ind] = mas[size - 1];
        mas[size - 1] = mx;
        size--;
    }
}

int main()
{
    srand(time(0));
    int size = 30000;
    int *mas = new int[size];
    for (int i = 0; i < size; i++)
        mas[i] = rand() % 100;
    unsigned long int s = clock();
    selection(mas, size);
    unsigned long int f = clock();
    cout << f - s << '\n';
    return 0;
}