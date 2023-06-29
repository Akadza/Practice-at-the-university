#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <time.h>
#include <cmath>

using namespace std;


class Matrix {
public:
    static const int size = 8;
    double mat[size][size] = { { 1, 2, 8, 2}, {2, 6, 1, 5}, {9, 6, 4, 1}, {5, 7, 1, 2} };
    double copymat[size][size]; // матрица для проверки.
    double identity_mat[size][size];
    string path;

    

public:
    // чтение данных из файла.
    void read_file() {
        ifstream dataFile(path);
        string data;
        double coef;
        int line = 0, j = 0;

        if (dataFile.is_open())
        {
            while (getline(dataFile, data))
            {
                istringstream ss(data);
                for (int i = 0; i < size; i++)
                {
                    ss >> coef;
                    mat[line][i] = coef;
                }
                line++;
            }
        }
        else {
            cout << "File wasn't found!";
            return;
        }
    }

    // показывает матрицу.
    void show(int len = 0) {
        for (int i = 0; i < size - len; i++)
        {
            for (int j = 0; j < size; j++)
            {
                printf("%10.5lf ", mat[i][j]);
            }
            cout << endl;
        }
        cout << endl;
    }

    // генерирует рандомную матрицу. size x size;
    void rand_mat(double left = -100 , double right = 100) {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                mat[i][j] = abs(sin(rand())) * (right - left) + left;//((double)(rand()) / RAND_MAX * (right - left) + left);
            }
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                copymat[i][j] = mat[i][j];
            }
        }
    }
    
    // рекурсивная функция для приведения матрицы к ступенчатому виду. Базовый случай, если матрица осталась 1 на 1.
    void matrix_stepped(double A[][size], double id_mat[][size], int len = size) {
        if (len == 1) return;

        double k;
        int index = size - len;
        for (int i = 0; i < len - 1; i++)
        {
            k = A[0][index] / (-A[i + 1][index]);
            // изменим строки ниже i
            for (int j = index; j < size; j++)
            {
                A[i + 1][j] += A[0][j] / k;
                // изменим единичную матрицу.
            }
            for (int j = 0; j < size; j++)
            {
                id_mat[i + 1][j] += id_mat[0][j] / k;
            }
        }
        matrix_stepped(&A[1], &id_mat[1], len - 1);
    }

    // приведение матрицы к единичному виду.
    void identity_matrix(double A[][size], double id_mat[][size], int lim = 0) {

        // изменим последние элементы по диагонали.
        if (lim == size - 1) {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    id_mat[i][j] /= A[i][i];
                }
                A[i][i] /= A[i][i];
            }
            return;
        }

        double k;
        int index = size - lim - 1; // ограничит матрицу по горизонтали и вертикали.
        for (int i = index; i >= 1; i--)
        {
            k = A[index][index] / (-A[i - 1][index]);
            for (int j = 0; j < size; j++)
            {
                A[i - 1][j] += A[index][j] / k;
                id_mat[i - 1][j] += id_mat[index][j] / k;
            }
        }
        identity_matrix(A, id_mat, lim + 1);
    }

    // копирует одно значение матрицы в другую.
    void copy_mat(double A_mat[][size], double B_mat[][size]) {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                B_mat[i][j] = A_mat[i][j];
            }
        }
    }

    // перемножение матриц.
    void multiplication(double mat[][size], double id_mat[][size]) {
        cout << "\n";
        double c[size][size] = {0};
        double sum = 0.0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                for (int k = 0; k < size; k++)
                {
                    c[i][j] += mat[i][k] * id_mat[k][j];
                }
                printf("%10.6lf ", c[i][j]);
            }
            cout << endl;
        }
    }

    // нахождение определителя матрицы.
    double det(double** mat, int lenMat) {
        // базовый случай 2 на 2.
        if (lenMat == 2) return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        double determinant = 0.0;
        for (int i = 0; i < lenMat; i++) // элементы для перемножения на миноры.
        {
            double** minor = new double*[lenMat - 1];
            for (int m = 0; m < lenMat - 1; m++) 
            {
                minor[m] = new double[lenMat - 1];
            }
            for (int j = 1; j < lenMat; j++)
            {
                int row = 0;
                int col = i - 1;
                for (int k = 0; k < lenMat; k++)
                {
                    if (i == k) continue;
                    minor[col][row++] = mat[i][j];
                }
            }
            determinant += pow(1, i) * mat[0][i] * det(minor, lenMat - 1);
            for (int m = 0; m < lenMat - 1; m++) {
                delete[] mat[m];
            }
            delete[] mat;
        }
        return determinant;
    }

    Matrix(string dataFilePath) {
        path = dataFilePath;
        cout << "matrix " << size << "x" << size << endl;
        // заполним единичную матрицу.
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j) identity_mat[i][j] = 1;
                else identity_mat[i][j] = 0;
            }
        }
    }
};

int main()
{
    srand(time(NULL));
    

    Matrix matrix("dataFile.txt");
    
    matrix.rand_mat(-50.0, 100.0);
    matrix.copy_mat(matrix.mat, matrix.copymat);
    matrix.show();
    cout << "\n\n";
    matrix.matrix_stepped(matrix.mat, matrix.identity_mat);

    matrix.identity_matrix(matrix.mat, matrix.identity_mat);
    matrix.show();
    
    cout << "Identity matrix: END: \n";
    for (int i = 0; i < matrix.size; i++)
    {
        for (int j = 0; j < matrix.size; j++)
        {
            printf("%10.5lf ", matrix.identity_mat[i][j]);
        }
        cout << endl;
    }

    cout << "\n\ncheck martix:" << endl;
    matrix.multiplication(matrix.copymat, matrix.identity_mat);

    return 0;
}