#include <iostream>
#include <time.h>
#include <fstream>
#define RIGHT 100
#define LEFT -50
using namespace std;

void bubble_sort(int* array, int length, int &countIt);

int main()
{
    srand(time(0));
    const int SIZE = 10000;
    int array[SIZE];

    double second = 0.0;
    int countIteration = 0;

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = LEFT + rand() % (RIGHT - LEFT + 1);
    }
    
    cout << "\n";

    clock_t begin = clock();
    bubble_sort(array, SIZE, countIteration);
    clock_t end = clock();

    second += (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "Time: " << second << endl;
    cout << "count iteration: " << countIteration << endl;

    return 0;
}

void bubble_sort(int* array, int length, int &countIt) {
    bool key = true;
    while (key)
    {
        key = false;

        for (int i = 0; i < length - 1; i++)
        {
            if (array[i] < array[i + 1])
            {
                int value = array[i];
                array[i] = array[i + 1];
                array[i + 1] = value;
                key = true;
            }
        }
        countIt++;
    }

}
