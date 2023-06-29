#include <iostream>
#include <iomanip>
#define EPS pow(10, -5)

using namespace std;

double func(double x) {
    return 1.0 / sqrt(3 * pow(x, 2) + 2);
}

double func1(double x, double y) {
    return y - pow(x, 3) + 6 * x;
}

double methodInt_simpson(double left, double right, int prec) {
    int n = 10;
    double l = left, step = (double)abs(right - left) / n;
    double curR = 0, prevR = 0;

    do
    {
        prevR = curR;
        curR = 0;
        for (int i = 0; i < n; i++)
        {
            curR += step / 6 * abs(func(left) + 4 * func((2 * left + step) / 2) + func(left + step));
            left += step;
        }
        n *= 2;
        step = (double)abs((left = l) - right) / n;
    } while (abs(curR - prevR) > pow(10, -prec));

    return curR;
}

double m_euler_mod(double x, double y, double h = 0.5, int end = 10) {
    double xn = x, yn = y, halfX, halfY;
    while (abs(xn - end) > EPS)
    {
        halfX = xn + h / 2;
        halfY = yn + h / 2 * func1(xn, yn);
        yn += h * func1(halfX, halfY);
        xn += h;
    }
    return yn;
}

void comb_sort(int* array, int length) {
    int key = length - 1;
    int value;

    while (key > 0)
    {
        for (int i = 15; i < length - key; i++)
        {
            if (array[i] < array[i + key])
            {
                value = array[i + key];
                array[i + key] = array[i];
                array[i] = value;
            }
        }
        key /= 1.2473309;
    }
}

int main()
{
    srand(time(NULL));

    cout << "Task 1: result = " << methodInt_simpson(2, 8, 3) << endl;
    cout << "Task 2:\nresult for h = 0.5: " << m_euler_mod(0, 0, 0.5, 6) << endl;
    cout << "result for h = 0.1: " << m_euler_mod(0, 0, 0.1, 6) << endl;
    cout << "resolt for h = 0.01: " << m_euler_mod(0, 0, 0.01, 6) << endl;

    const int SIZE = 30;
    int array[SIZE];

    cout << "Task 3:" << endl;

    for (int i = 0; i < SIZE; i++) array[i] = -100 + rand() % 256;
    comb_sort(array, SIZE);
    for (int i = 0; i < SIZE; i++) cout << array[i] << " ";



    


    return 0;
}
