#include <iostream>
using namespace std;

int main()
{

    const int N = 5;          // задаем размер матрицы
    int a[N][N];        // и инициализируем ее
    for (int ik = 0; ik < N; ik++)
        for (int jk = 0; jk < N; jk++)
            a[ik][jk] = 0;          // заполнив для удобства нулями

    for (int ik = 0; ik < N; ik++) {     //назовем его "Основной цикл"
        for (int jk = 0; jk < N; jk++) {
            if (!(ik == 0 || ik == N - 1 || jk == 0 || jk == N - 1))
                continue;      // Временное условие для фильтрации элементов внесшего "кольца"
            int i = ik + 1;     // Номера строк и столбцов приводим в удобный
            int j = jk + 1;     // в математическом плане вид (от 1 до N)  
            //  ... здесь будем вставлять основной код вычислений
            int Xs = i + j - 1;
            a[ik][jk] = j - i;
            int switcher = (j - i + N) / N;
            int Ic = abs(i - N / 2 - 1) + (i - 1) / (N / 2) * ((N - 1) % 2);
            int Jc = abs(j - N / 2 - 1) + (j - 1) / (N / 2) * ((N - 1) % 2);
            int Ring = N / 2 - (abs(Ic - Jc) + Ic + Jc) / 2;
            Xs = i - Ring + j - Ring - 1;
            int Coef = 4 * Ring * (N - Ring);
            a[ik][jk] = Coef + switcher * Xs + abs(switcher - 1) * (4 * (N - 2 * Ring) - 2 - Xs);
        }
    }

    for (int ik = 0; ik < N; ik++) {          //Блок "Вывод массива"
        for (int jk = 0; jk < N; jk++) {
            printf("%02d ", a[ik][jk]);	// дополняем число ведущими нулями
        }
        cout << endl;
    }
    return 0;
}