#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>

using namespace std;


// вывод матрицы.
void show(double** mat, int size);


// генерация рандомной матрицы.
void rand_mat(double** mat, int size, double left, double right);


// нахождение определителя матрицы.
double det(double** mat, int lenMat);


int main()
{
    //srand(time(NULL));
    int size;
    cout << "Enter a size: ";
    cin >> size;

    double** mat = new double* [size];
    for (int i = 0; i < size; i++)
    {
        mat[i] = new double[size];
    }
    
    rand_mat(mat, size, -5.0, 10);
    show(mat, size);
    double res = det(mat, size);
    cout << "det matrix = " << res << endl;

    // очистим память.
    for (int i = 0; i < size; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;

    return 0;
}


void show(double** mat, int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(size * 2) << mat[i][j] << " ";
        }
        cout << "\n";
    }
}


void rand_mat(double** mat, int size, double left = -100.0, double right = 100.0) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mat[i][j] = abs(sin(rand())) * (right - left) + left;
        }
    }
}


double det(double** mat, int lenMat) {
    // базовый случай 2 на 2.
    if (lenMat == 1) return mat[0][0];
    if (lenMat == 2) return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    double determinant = 0.0;
    for (int i = 0; i < lenMat; i++) // элементы для перемножения на миноры.
    {
        double** minor = new double* [lenMat - 1];
        for (int m = 0; m < lenMat - 1; m++)
        {
            minor[m] = new double[lenMat - 1];
        }
        for (int j = 1; j < lenMat; j++)
        {
            int row = 0;
            int col = j - 1;
            for (int k = 0; k < lenMat; k++)
            {
                if (i == k) continue;
                minor[col][row] = mat[j][k];
                row++;
            }
        }
        determinant += pow(-1, i + 2) * mat[0][i] * det(minor, lenMat - 1);
        for (int m = 0; m < lenMat - 1; m++) {
            delete[] minor[m];
        }
        delete[] minor;
    }
    return determinant;
}