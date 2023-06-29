#include <iostream>
#include <windows.h>
#include <time.h>

#define RIGHT 100
#define LEFT -50
using namespace std;

void hairbrush_sort(int* array, int length, int &countIt);

int main()
{
    srand(time(0));

    double timeSpent = 0.0;
    int countIteration = 0;
    
    const int SIZE = 10000;
    int array[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = LEFT + rand() % (RIGHT - LEFT + 1);
    }

    /* for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n"; */

    
    clock_t begin = clock();
    
    hairbrush_sort(array, SIZE, countIteration);

    clock_t end = clock();
    /*
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";    
    }*/
    timeSpent += (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n Time: " << timeSpent << endl;
    cout << "count iteration: " << countIteration << endl;

    return 0;
}

void hairbrush_sort(int* array, int length, int &countIt) {
    int key = length - 1;
    
    while (key > 0)
    {
        for (int i = 0; i < length - key; i++)
        {
            if (array[i] < array[i + key])
            {
                int value = array[i + key];
                array[i + key] = array[i];
                array[i] = value;
            } 
            countIt++;
        }
        key /= 1.2473309;
        
    }
    
}

