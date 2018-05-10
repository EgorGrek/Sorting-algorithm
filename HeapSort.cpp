#include <ctime>
#include <iostream>
using namespace std;

void heapify(int *mas, int begin, int end)
{
    int max;
    for (int i = begin; 2 * i + 1 < end;)
    {
        if (2 * i + 2 < end)
        {
            if (mas[i] < mas[2 * i + 2] || mas[i] < mas[2 * i + 1])
            {
                max = mas[2 * i + 2];
                if (max <= mas[2 * i + 1])
                {
                    int temp = mas[i];
                    mas[i] = mas[2 * i + 1];
                    mas[2 * i + 1] = temp;
                    i = 2 * i + 1;
                }
                else
                {
                    int temp = mas[i];
                    mas[i] = mas[2 * i + 2];
                    mas[2 * i + 2] = temp;
                    i = 2 * i + 2;
                }
            }
            else
                break;
        }
        else if (mas[i] < mas[2 * i + 1])
        {
            int temp = mas[i];
            mas[i] = mas[2 * i + 1];
            mas[2 * i + 1] = temp;
            i = 2 * i + 1;
        }
        else
            break;
    }
}
void heapsort(int *mas, int begin, int end)
{
    for (int i = (end - 1) / 2; i >= begin; i--)
        heapify(mas, i, end);

    for (int i = end - 1; i > begin; i--)
    {
        int temp = mas[i];
        mas[i] = mas[begin];
        mas[begin] = temp;
        heapify(mas, begin, i - 1);
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
    heapsort(mas, 0, size);
    int f = clock();
    cout << f - s << '\n';

    for (int i = 0; i < size; i++)
        cout << mas[i] << ' ';
    return 0;
}