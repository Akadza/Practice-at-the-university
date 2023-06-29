#include <iostream>
#include <windows.h>
#include <time.h>
#include <fstream>

using namespace std;

void generation(int count, int start, int end);
void read_file(string path, int *array, int count);
void hairbrush_sort(int* array, int length, unsigned long int& countIt);
void hairbrush_sort_f2(int* array, int length, unsigned long int& countIt);
void selection_sort(int* array, int length, unsigned long int& countIt);
void bubble_sort(int* array, int length, unsigned long int& countIt);
void qsort(int* array, int length, unsigned long int& countIt);

int main()
{
    srand(time(0));

    double timeSpent = 0.0;
    unsigned long int countIteration = 0;

    const int SIZE = 300000;
    int array[SIZE];

    generation(SIZE, -25000, 25000);
    read_file("input.txt", array , SIZE);
    
    clock_t begin = clock();
    qsort(array, SIZE, countIteration);
    clock_t end = clock();

    timeSpent = (double)(end - begin) / CLOCKS_PER_SEC;
    cout << "\n Time: " << timeSpent << endl;
    cout << "count iteration: " << countIteration << endl;

    return 0;
}

void hairbrush_sort(int* array, int length, unsigned long int& countIt) {
    int key = length - 1;
    int value;

    while (key > 0)
    {
        for (int i = 0; i < length - key; i++)
        {
            if (array[i] < array[i + key])
            {
                value = array[i + key];
                array[i + key] = array[i];
                array[i] = value;
                countIt++;
            }
        }
        key /= 1.2473309;

    }

}


void selection_sort(int* array, int length, unsigned long int& countIt) {

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
        if (i != indexMaxValue)
        {   
            int value = array[i];
            array[i] = array[indexMaxValue];
            array[indexMaxValue] = value;
            countIt++;
        }
    }
}

        
void bubble_sort(int* array, int length, unsigned long int& countIt) {
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
                countIt++;
            }
        }
    }
}


void generation(int count, int start, int end) {
    ofstream generateValues("input.txt", ios_base::out);
    
    if (generateValues.is_open())
    {
        for (int i = 0; i < count; i++)
        {
            generateValues << start + rand() % (end - start + 1) << endl;
        }
        generateValues.close();
    }
    else {
        cout << "\nSomething get wrong!" << endl;
    }
}


void read_file(string path, int* array, int count) {
    ifstream readValues(path, ios_base::in);

    if (readValues.is_open())
    {
        for (int i = 0; i < count; i++)
        {
            readValues >> array[i];
        }

        readValues.close();
    }
    else {
        cout << "\nSomething get wrong!" << endl;
    }
}


void hairbrush_sort_f2(int* array, int length, unsigned long int& countIt) {
    int g = length / 2;
    int value;
    bool key = true;

    while (g > 0)
    {
        key = false;
        for (int i = 0; i < length - g; i++)
        {
            if (array[i] < array[i + g])
            {
                key = true;
                value = array[i];
                array[i] = array[i + g];
                array[i + g] = value;
                countIt++;
            }
        }
        if (g == 1 && key)
        {
            continue;
        }
        g /= 2;
    }
}

void qsort(int* array, int length, unsigned long int& countIt) {
    int i = 0;
    int j = length - 1;

    int medium = array[length / 2];

    do {
        while (array[i] < medium) {
            i++;
        }
        while (array[j] > medium) {
            j--;
        } 

        if (i <= j) {
            int value = array[i];
            array[i] = array[j];
            array[j] = value;

            i++;
            j--;
            countIt++;
        }
    } while (i <= j);

        
    if (j > 0) {
        qsort(array, j + 1, countIt);
    }
    if (i < length) {
        qsort(&array[i], length - i, countIt);
    }
}