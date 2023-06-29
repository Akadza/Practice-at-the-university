#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

const int row = 5;



void matrix_stepped(double A[][row], double* B, int size);  // приведение матрицы к ступенчатому виду.
void method_Gauss(double A[][row], double* B);
void method_Gauss_Zeidel(double A[][row], double* B, double eps);


// показывает массив
void show(double A[][row], int size) {
    for (int i = 0; i < row - size; i++)
    {
        for (int j = 0; j < row; j++)
        {
            cout << setw(10) << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


// чтение данных из файла
void read_file(string path, double A[][row], double* B) {
    ifstream dataFile(path);
    string data;
    double coef;
    int line = 0, j = 0;

    if (dataFile.is_open())
    {
        while (getline(dataFile, data))
        {
            istringstream ss(data);
            ss >> coef;
            B[j++] = coef;
            for (int i = 0; i < row; i++)
            {
                ss >> coef;
                A[line][i] = coef;              
            }
            line++;
        }
    }
    else {
        cout << "File wasn't found!";
        return;
    }
}


// копирует значение из A массива в B массив
void copyArr(double *A, double* B, int size) {
    for (int i = 0; i < size; i++) {
        B[i] = A[i];
    }
}


// результат b для i-строки по X элементам;
double result(double A[][row], double* X, int index = 0) {
    double b0 = 0;
    for (int j = 0; j < row; j++) {
        b0 += A[index][j] * X[j];
    }
    return b0;
}


// возращает максимальное значение b между i-строкими матрицы.
double max_deltaArr(double A[][row], double *newX, double *prevX) {
    double maxDelta = abs(result(A, newX) - result(A, prevX));
    double newValue;
    for (int i = 1; i < row; i++)
    {
        newValue = abs(result(A, newX, i) - result(A, prevX, i));
        maxDelta = (maxDelta < newValue) ? newValue : maxDelta;
    }

    return maxDelta;
}


int main()
{
    double A[row][row], B[row];
    
    const double eps = 0.1;
    double b = 0;
    double arrX[5] = { -36.7100864844864, -43.6700282671148, -37.762445557917, -49.291418770363, -24.7507751730596 };
    read_file("dataFile9.txt", A, B);

    // сделаем проверку для метода гаусса.
    cout << "Methos Gauss:" << endl;
    for (int i = 0; i < row; i++)
    {
        cout << setprecision(7) << result(A, arrX, i) << endl;
    }

    cout << endl;
    method_Gauss(A, B);

    cout << "\n\n";

    cout << "Methos Gauss Zeidel:" << endl;
    read_file("dataFile9.txt", A, B);
    show(A, 0);
    method_Gauss_Zeidel(A, B, pow(10, -4));

    return 0;
}

// рекурсивная функция для приведения матрицы к ступенчатому виду. Базовый случай, если матрица осталась 1 на 1
void matrix_stepped(double A[][row], double* B, int size) {
    if (size == 1) return;
    
    double k;
    int index = row - size;
    for (int i = 0; i < size - 1; i++)
    {
        k = A[0][index] / (-A[i + 1][index]);
        // изменим строки ниже i
        for (int j = index; j < row; j++)
        {
            A[i + 1][j] += A[0][j] / k;
        }
        B[i + 1] += B[0] / k;
    }
    //show(A, row - size);
    matrix_stepped(&A[1], &B[1], size - 1);
}


void method_Gauss(double A[][row], double* B) {
    matrix_stepped(A, B, row); // привели матрицу к ступенчатому
    show(A, 0);
    double arrX[row] = {0};
    arrX[row - 1] = B[row - 1] / A[row - 1][row - 1];
    for (int i = row - 2; i >= 0; i--)
    {
        arrX[i] = B[i];
        for (int j = i + 1; j < row; j++)
        {
            arrX[i] -= A[i][j] * arrX[j];
        }
        arrX[i] /= A[i][i];
    }
    
    // выведем данные в консоль
    for (int i = 0; i < row; i++)
    {
        cout << setprecision(15) << "X[" << i << "] = " << arrX[i] << endl;
    }

    // запишем данные в файл.
    read_file("dataFile9.txt", A, B);
    ofstream answerFile;
    answerFile.open("answer_data.txt");
    if (answerFile.is_open())
    {
        answerFile << "Result for Method Gauss:\n" << endl;
        for (int i = 0; i < row; i++)
        {
            answerFile << setprecision(15) << "X[" << i + 1 << "] = " << arrX[i] << endl;
        }
        answerFile << "\nDelta:" << endl;
        for (int i = 0; i < row; i++)
        {
            answerFile << fixed << setprecision(2) << abs(B[i]) << " - " \
                       << setprecision(15) << abs(result(A, arrX, i)) \
                       << " = " << abs((B[i]) - (result(A, arrX, i))) << endl;
        }
    }
    answerFile.close();
}


void method_Gauss_Zeidel(double A[][row], double *B, double eps) {
    int count = 0;
    double prevX[row] = {};
    double newX[row] = {};

    while (true) {
        newX[0] = (B[0] - A[0][1] * prevX[1] - A[0][2] * prevX[2] - A[0][3] * prevX[3] - A[0][4] * prevX[4]) / A[0][0]; // x1
        newX[1] = (B[1] - A[1][0] * newX[0] - A[1][2] * prevX[2] - A[1][3] * prevX[3] - A[1][4] * prevX[4]) / A[1][1]; // x2
        newX[2] = (B[2] - A[2][0] * newX[0] - A[2][1] * newX[1] - A[2][3] * prevX[3] - A[2][4] * prevX[4]) / A[2][2]; // x3
        newX[3] = (B[3] - A[3][0] * newX[0] - A[3][1] * newX[1] - A[3][2] * newX[2] - A[3][4] * prevX[4]) / A[3][3]; // x4
        newX[4] = (B[4] - A[4][0] * newX[0] - A[4][1] * newX[1] - A[4][2] * newX[2] - A[4][3] * newX[3]) / A[4][4]; // x5

        double delta = max_deltaArr(A, newX, prevX); // находим максимальную разность b0 и b1 по каждой строке.
        if (delta < eps) break;
        copyArr(newX, prevX, row);
    }
    
    // вывод и ввод данных
    for (int i = 0; i < row; i++)
    {
        cout << "x[" << i << "] = " << newX[i] << " { b = " << result(A, newX, i) << " }" << endl;
    }
    // запишем данные в файл.
    ofstream answerFile;
    answerFile.open("answer_data.txt", ios::app);
    if (answerFile.is_open())
    {
        answerFile << "\nResult for Method Gauss-Zeidel:\n" << endl;
        for (int i = 0; i < row; i++)
        {
            answerFile << setprecision(15) << "X[" << i + 1 << "] = " << newX[i] << endl;
        }
        answerFile << "\nDelta:" << endl;
        for (int i = 0; i < row; i++)
        {
            answerFile << fixed << setprecision(2) << abs(B[i]) << " - " \
                                << setprecision(15) << abs(result(A, newX, i)) << " = " \
                                << abs(result(A, newX, i) - B[i]) << endl;
        }
    }
    answerFile.close();
}