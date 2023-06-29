#include <iostream>
#include <vector>
#include <time.h>

using namespace std;


typedef struct {
    char name[64];
    int price;
} FRUIT;

typedef struct data_fruit {
    FRUIT data;
    struct data_fruit* next_fruit;
} OBJ;

vector<OBJ*> pFruits(64);


int hash_f(char* nameF);
void add_fruit(FRUIT fruit);
int find_fruit(char* name);
int fp(); // насколько заполнен

int main()
{
    srand(time(NULL));
    // 1 - динамический массив.
    // 1.1 хэш-функция. 
    // 2 - элементы - это есть указатели на структуру.
    // 3 - структура - это есть имя продукта, его цена и указатель на следующую структуру. (*для коллизии)
    // 4 - поиск по имени продукта. возращаем его цену.
    // 5 - удаление - применяем способ рехэширования.
    // 6 - добавление.
    // 7 - изменение размера хэш-таблицы. при заполнении 70%
    
    char nameF[64] = "A";
    char name1[64] = "GbX";
    char name2[64] = "apelsin";
    char name3[64] = "mandarin";

    add_fruit({ "A", 100 });
    add_fruit({ "GbX", 123 });
    cout << find_fruit(nameF) << endl;
    cout << find_fruit(name1) << endl;
    add_fruit({ "apelsin", 128 });
    cout << find_fruit(name2) << endl;
    add_fruit({ "mandarin", 300 });
    cout << find_fruit(name3) << endl;

    for (int i = 0; i < pFruits.size(); i++)
    {
        char s = (char)(rand() % (255));
        add_fruit({ s, 10});
    }


    for (int i = 0; i < pFruits.size(); i++)
    {
        cout << i + 1 << ": " << pFruits[i] << endl;
    }

    cout << "\nOur table = " << fp() << "%" << endl;

    return 0;
}


int hash_f(char* nameF) {
    int hashValue = 0;
    for (int i = 0; i < strlen(nameF); i++) hashValue += (int)nameF[i];

    return hashValue % pFruits.size();
}

void add_fruit(FRUIT fruit) {
    int indexHashV = hash_f(fruit.name);
    OBJ* ptr = new OBJ;
    OBJ* ptrF = new OBJ;

    ptr = pFruits[indexHashV];
    ptrF->data = fruit;
    ptrF->next_fruit = NULL;
    
    if (ptr == NULL)
    {
        pFruits[indexHashV] = ptrF;
        return;
    }

    while (ptr->next_fruit != NULL)
    {
        ptr = ptr->next_fruit;
    }
    ptr->next_fruit = ptrF;
}

int find_fruit(char* name) {
    int indexHashV = hash_f(name);
    OBJ* ptrF = new OBJ;
    ptrF = pFruits[indexHashV];

    while (strcmp(ptrF->data.name, name) != 0)
    {
        if (ptrF->next_fruit == NULL)
        {
            cout << "Fruit doesn't exist!" << endl;
            return 0;
        }
        else ptrF = ptrF->next_fruit;
    }
    return ptrF->data.price;
}

int fp() {
    double precent = 0;
    for (int i = 0; i < pFruits.size(); i++)
    {
        if (pFruits[i] != NULL) precent++;
    }
    return precent / pFruits.size() * 100;
}