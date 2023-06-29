#define _SRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

// сколько элементов больше среднего значения положительных элементов массива
int len_num(int num); // длина числа.
int find_min_value(int* array, int size); // минимальное значение среди чисел массива.
int count_value_average(int* array, int size); // считывает среднее значение положительных элементов массива
int summ_num(int num_num); // сумма цифр минимального элемента
int max_values_mod(int* array, int size); // максимальное число из массива кратное 7

int main()
{
    srand(time(0));
    const int SIZE = 42;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = -255 + rand() % 501;
        printf("%5d", arr[i]);
    }

    printf("\n\n%d\n", count_value_average(arr, SIZE));
    printf("%d\n", max_values_mod(arr, SIZE));
    int numberMin = find_min_value(arr, SIZE);
    printf("MIN = %d / Summ = %d\n\n", numberMin, summ_num(numberMin));

    return 0;
}

int len_num(int num) {

    return log10(num) + 1;
}
int count_value_average(int* arr, int size) {
    int count_value = 0, count = 0;
    double average = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            average += arr[i];
            count++;
        }
    }
    average /= count;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > average)
        {
            count_value++;
        }
    }

    return count_value;
}

int find_min_value(int* array, int size) {
    int m_num = array[0];
    for (int i = 0; i < size; i++)
    {
        m_num = (array[i] < m_num) ? array[i] : m_num;
    }

    return m_num;
}

int summ_num(int min_num) {
    min_num = abs(min_num);
    int sum = 0, value = 0, length_num = len_num(min_num);

    for (int i = length_num - 1; i >= 0; i--)
    {
        value = min_num / pow(10, i);
        sum += value;
        min_num -= value * pow(10, i);
    }

    return sum;
}


int max_values_mod(int* array, int size) {
    int max_v = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] % 7 == 0)
        {
            max_v = array[i];
            break;
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (array[i] % 7 == 0)
        {
            max_v = (max_v > array[i]) ? max_v : array[i];
        }
    }

    return max_v;
}