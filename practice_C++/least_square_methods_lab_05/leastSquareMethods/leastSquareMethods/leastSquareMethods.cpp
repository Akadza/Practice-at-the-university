#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
const int len = 9;
double copM[6][6];

void matrix_stepped(double A[][6], double* B, int size);  // приведение матрицы к ступенчатому виду.
void method_Gauss(double A[][6], double* B);


// считывает данные x and y из файла
void read_data(double* x, double* y, string path) {
    ifstream dataFile(path);
    if (dataFile.is_open())
    {
        double valX, valY;
        int i = 0;
        while (dataFile >> valX >> valY)
        {
            x[i] = valX;
            y[i++] = valY;
        }
    }
    else {
        cout << "\nFile wasn't found!\n";
    }
    dataFile.close();
}


// выводит данные x and y.
void showXY(double* x, double* y) {
    cout << "X: ";
    for (int i = 0; i < len; i++)
    {
        cout << setw(9) << x[i] << " ";
    }
    cout << "\nY: ";
    for (int i = 0; i < len; i++)
    {
        cout << setw(9) << y[i] << " ";
    }
}


// вывод матрицы.
void show(double arr[][6], int size = len) {
    cout << "\n Matrix:\n";
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(14) << arr[i][j] << " ";
        }
        cout << "\n";
    }
}


double sum(double* x, int power) {
    double s = 0.0;
    for (int i = 0; i < len; i++)
    {
        s += pow(x[i], power);
    }
    return s;
}


double sum(double* x, double* y, int power) {
    double s = 0.0;
    for (int i = 0; i < len; i++)
    {
        s += pow(x[i], power) * y[i];
    }
    return s;
}


// копирование значение одной матрицы в другую.
void copyMat(double x[][6], double y[][6]) {
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            y[i][j] = x[i][j];
        }
    }
}


// метод МНК.
void lSQ(double* x, double* y) {
    const int l = 6;
    double S[l][l];
    double B[l];
    
    // заполнение матрицы x-ами.
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            S[i][j] = sum(x, 10 - i - j);
        }
    }
    // заполнение свободных коэффициентов.
    for (int i = 0; i < l; i++)
    {
        B[i] = sum(x, y, l - 1 - i);
    }
    copyMat(S, copM);
    show(S, 6);
    cout << "matrix free coef:\n";
    for (int i = 0; i < l; i++)
    {
        cout << fixed << setw(12) << B[i] << " ";
    }
    matrix_stepped(S, B, 6);
    show(S, 6);
    cout << "\n\n";
    method_Gauss(S, B);

    return;
}

int main()
{
    double x[len], y[len];
    read_data(x, y, "dataFile.txt");
    showXY(x, y);
    lSQ(x, y);





    return 0;
}



void matrix_stepped(double X[][6], double* B, int size) {
    if (size == 1) return;

    double k;
    int index = 6 - size;
    for (int i = 0; i < size - 1; i++)
    {
        k = X[0][index] / (-X[i + 1][index]);
        // изменим строки ниже i
        for (int j = index; j < 6; j++)
        {
            X[i + 1][j] += X[0][j] / k;
        }
        B[i + 1] += B[0] / k;
    }
    matrix_stepped(&X[1], &B[1], size - 1);
}


void method_Gauss(double X[][6], double* B) {
    matrix_stepped(X, B, 6); // привели матрицу к ступенчатому
    double arrCoef[6] = { 0 };
    arrCoef[6 - 1] = B[6 - 1] / X[6 - 1][6 - 1];
    for (int i = 6 - 2; i >= 0; i--)
    {
        arrCoef[i] = B[i];
        for (int j = i + 1; j < 6; j++)
        {
            arrCoef[i] -= X[i][j] * arrCoef[j];
        }
        arrCoef[i] /= X[i][i];
    }

    // выведем данные в консоль
    for (int i = 0; i < 6; i++)
    {
        cout << setprecision(15) << "coef[" << i << "] = " << arrCoef[i] << endl;
    }
    
    for (int i = 0; i < 6; i++)
    {
        double res = 0.0;
        for (int j = 0; j < 6; j++)
        {
            res += copM[i][j] * arrCoef[j];
        }
        cout << "\nResult: " << i << " = " << res;
    }
    cout << "\n\n";
    
}