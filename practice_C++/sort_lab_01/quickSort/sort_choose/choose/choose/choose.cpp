#include <iostream>
#include <time.h>
#define RIGHT 100
#define LEFT -50

using namespace std;
void selection_sort(int* array, int length, int &countIt);

int main()
{
    srand(time(0));
    const int SIZE = 100000;
    int array[SIZE];

    double second = 0.0;
    int countIteration = 0;

    for (int i = 0; i < SIZE; i++)
    {
        array[i] = LEFT + rand() % (RIGHT - LEFT + 1);
        // cout << array[i] << " ";
    }

    cout << "\n";
    clock_t begin = clock();
    selection_sort(array, SIZE, countIteration);
    clock_t end = clock();

    second += (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "Time: " << second << endl;
    cout << "count iteration: " << countIteration << endl;
    /*for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }*/

    
}
    
void selection_sort(int* array, int length, int &countIt) {
    
    for (int i = 0; i < length - 1; i++)
    {
        int indexMaxValue = i;
        
        for (int j = i + 1; j < length; j++)
        {
            if (array[indexMaxValue] < array[j])
            {
                indexMaxValue = j;
            }
        }
        int value = array[i];
        array[i] = array[indexMaxValue];
        array[indexMaxValue] = value;
        countIt++;
    }
}

