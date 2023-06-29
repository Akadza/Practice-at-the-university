#include <iostream>
#include <iomanip>

using namespace std;

double methodInt_right_rectangle(const double left, double rigth, int prec);
double methodInt_left_rectangle(double left, const double right, int prec);
double methodInt_middle_rectangle(double left, const double right, int prec);
double methodInt_trapeze(double left, double right, int prec);
double methodInt_simpson(double left, double right, int prec);

int main()
{
    const int precision = 5; // точность знаков после запятой
    cout << "R\n" << setprecision(precision) << methodInt_right_rectangle(0, 4, precision) << "\n\n";
    cout << "L\n" << setprecision(precision) << methodInt_left_rectangle(0, 4, precision) << "\n\n";
    cout << "M\n" << setprecision(precision) << methodInt_middle_rectangle(0, 4, precision) << "\n\n";
    cout << "T\n" << setprecision(precision) << methodInt_trapeze(0, 4, precision) << "\n\n";
    cout << "S\n" << setprecision(precision) << methodInt_simpson(0, 4, precision) << "\n\n";
    return 0;
}

double func(double val) {
    return 1.0 / (5 - val);
}

double methodInt_right_rectangle(const double left, double right, int prec) {
    int n = 10;
    double r = right, step = (double)abs(right - left) / n;
    double curR = 0, prevR = 0;
    cout << "n" << setw(15) << "h" << setw(15) << "S" << setw(20) << "dS" << endl;

    do
    {
        prevR = curR;
        curR = 0;
        for (int i = 0; i < n; i++)
        {
            curR += abs(func(right)) * step;
            right -= step;
        }
        cout << n << setw(15) << step << setw(15) << curR << setw(20) << abs(curR - prevR) << endl;
        n *= 2;
        step = (double)abs((right = r) - left) / n;
        
        
    } while (abs(curR - prevR) > pow(10, -prec));

    return curR;
}


double methodInt_left_rectangle(double left, const double right, int prec) {
    int n = 10;
    double l = left, step = (double)abs(right - left) / n;
    double curR = 0, prevR = 0;
    cout << "n" << setw(15) << "h" << setw(15) << "S" << setw(20) << "dS" << endl;

    do
    {
        prevR = curR;
        curR = 0;
        for (int i = 0; i < n; i++)
        {
            curR += abs(func(left)) * step;
            left += step;
        }
        cout << n << setw(15) << step << setw(15) << curR << setw(20) << abs(curR - prevR) << endl;
        n *= 2; 
        step = (double)abs((left = l) - right) / n;
    } while (abs(curR - prevR) > pow(10, -prec));

    return curR;
}


double methodInt_middle_rectangle(double left, const double right, int prec) {
    int n = 10;
    double l = left, step = (double)abs(right - left) / n;
    double curR = 0, prevR = 0;
    cout << "n" << setw(8) << "h" << setw(10) << "S" << setw(15) << "dS" << endl;

    do
    {
        prevR = curR;
        curR = 0;
        for (int i = 0; i < n; i++)
        {
            curR += abs(func(left + step / 2)) * step;
            left += step;
        }
        cout << n << setw(8) << step << setw(10) << curR << setw(15) << abs(curR - prevR) << endl;
        n *= 2;
        step = (double)abs((left = l) - right) / n;
    } while (abs(curR - prevR) > pow(10, -prec));

    return curR;
}


double methodInt_trapeze(double left, double right, int prec) {
    int n = 10;
    double l = left, step = (double)abs(right - left) / n;
    double curR = 0, prevR = 0;
    cout << "n" << setw(8) << "h" << setw(15) << "S" << setw(15) << "dS" << endl;

    do
    {
        prevR = curR;
        curR = 0;
        for (int i = 0; i < n; i++)
        {
            curR += abs(((func(left) + func(left + step))) / 2) * step;
            left += step;
        }
        
        cout << n << setw(8) << step << setw(15) << curR << setw(15) << abs(curR - prevR) << endl;
        n *= 2;
        step = (double)abs((left = l) - right) / n;
    } while (abs(curR - prevR) > pow(10, -prec));

    return curR;
}


double methodInt_simpson(double left, double right, int prec) {
    int n = 10;
    double l = left, step = (double)abs(right - left) / n;
    double curR = 0, prevR = 0;
    cout << "n" << setw(5) << "h" << setw(10) << "S" << setw(15) << "dS" << endl;

    do
    {
        prevR = curR;
        curR = 0;
        for (int i = 0; i < n; i++) 
        {
            curR += step / 6 * abs(func(left) + 4 * func((2 * left + step) / 2) + func(left + step));
            left += step;
        }
        cout << n << setw(5) << step << setw(10) << curR << setw(15) << abs(curR - prevR) << endl;
        n *= 2;
        step = (double)abs((left = l) - right) / n;
    } while (abs(curR - prevR) > pow(10, -prec));

    return curR;
}