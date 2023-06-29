#include <iostream>

using namespace std;

// данные пользователя с полями:    
typedef struct {
    char firstNameUser[101]; // Имя
    char secondNmeUser[101]; // Фамилия
    char emailUser[101]; // email
    int index; // индекс пользователя.
} DATA_USER;

/* представление пользователя в виде структуры "DATA_USER"
 а также указателями на следующий структуру и предыдущую */
typedef struct data_user {
    DATA_USER user;
    struct data_user* prev;
    struct data_user* next;
} OBJ;

// Создаем указатель на начало и конец массива в виде указателей на структуру
// Примечание: Так как список изначально пустой. то они указывают на NULL
OBJ* startP = NULL, * endP = NULL; 

struct User {
    DATA_USER user; // описание пользователя

    int len_list() {
        /* Находит количество пользователей в списке 
           В качестве параметра - возращает целочисленное количество пользователей 
         */

        int lenResult = 0;

        OBJ* ptr = new OBJ; // выделяем память указателя на структуру OBJ
        ptr = startP; // начинаем идти от начала списка. ( указатель на начало )

        // до тех пор пока не дойдем до Объекта, указывающего на NULL. то есть конец массива.
        while (ptr != NULL)
        {
            ptr = ptr->next; // перемещаем указатель на следующую структуру
            lenResult++; // увеличиваем счетчик
        }
        return lenResult;
    }

    void add_user(unsigned int indexU, DATA_USER user)
    {
        /* Добавляет нового пользователя в список.
        * В качестве параметров передаем:
        1) индекс списка. на который мы хотим добавить пользователя.
        2) Структуру пользователя.
        */
        OBJ* ptr = new OBJ; // выделяем память под указатель на структуру.
        OBJ* obj = startP; // начинаем идти с начала списка.
        ptr->user = user; // в указатель передаем данные о пользователе.

        // Создаем исключение о выходе за границы списка.
        if (indexU > len_list()) {
            cout << "ExceptionOutOfBounds"; 
            return;
        }

        /*Рассмотрим 3 случая обработки связей.
        1) Если необходимо добавить пользователя в начало списка.
        2) Если необходимо добавить пользователя в конец списка.
        3) Если необходимо добавить пользователя в любую середину списка.
        */

        // Рассмотрим 1 случай:
        if (indexU == 0)
        {
            
            ptr->prev = NULL; // указатель на предыдущий элемент NULL, так как он первый
            startP = ptr; // начало как первый элемент.

            ptr->next = obj; // Устанавливаем связь на следующий объект 
                             //(Если элемент первый в списке, то он по-прежнему указывает на NULL.)

            if (obj != NULL) obj->prev = ptr; // Устанавливаем обратную связь.
            if (ptr->next == NULL) endP = ptr; // Если в списке было 0 элементов. То добавленный элемент будет как началом, так и концом.

            return;

        }
        // 3) перемещаем указатель до того элемента, после которого мы хотим добавить нового пользователя.
        for (int i = 0; i < indexU - 1; i++)
        {
            // obj - указатель на предыдущий элемент после которого мы хотим добавить новую струкруту в list.
            obj = obj->next;
        }
        
        ptr->prev = obj; // связь на предыдущую структуру.
        ptr->next = obj->next; // связь на следующую структуру.

        // Если предыдущий объект существует ( obj ). то устанавливаем связи:
        if (obj != NULL) {
        
            if (obj->next != NULL) obj->next->prev = ptr; // Если следующий объект сущестовал после obj
                                                          // То указатель на предыдущий элемент - Элемента obj->next, присваиваем новой структуре.
            obj->next = ptr; // предыдущий элемент (obj) теперь указывает на нашу новую следующую структуру.
        }
        // переопределяем начало и конец списка.
        if (ptr->next == NULL) endP = ptr;
        if (ptr->prev == NULL) startP = ptr;
    }
    
    void del_user(unsigned int indexU) {
       /* Удаляем пользователя из списка.
          В качестве параметра передаем индекс удаляемого объекта.
       */



        OBJ* obj = startP; // указываем на начало списка
        OBJ* ptr = new OBJ; // выделяем память под новый указатель на структуру.

        if (obj == NULL) return; // если список пуст, то ничего не делаем.
        
        /* Рассматриваем два случая. 
           1) когда удаляем первый элемент.
           2) когда удаляем последний элемент.
           3) когда удаляем любой другой, отличный от первого элемента и последнегоы.
        */ 
        
        // Рассмотрим 1 случай:
        if (indexU == 0) 
        {
            // В случае если длина списка равна 1. то удаляем элемент и переопределяем начало списка на NULL
            if (len_list() == 1) {
                startP = NULL;
                delete obj;
                return;
            }
            // Иначе переопределяем связи:
            obj->next->prev = NULL; // следующий указывает на NULL
            startP = startP->next; // начало списка теперь следующий указатель. (Становится текущим)
            delete obj;
            return;
        }
        // Рассмотрим 2 случай:
        else if (indexU == len_list() - 1)
        {
            obj = endP; // указатель на конец списка.
            obj->prev->next = NULL; // указываем на NULL предыдущим элементом от удаляемого
            endP = obj->prev; // переопределяем конец списка.
            delete obj;
            return;
        }
        // Рассмотрим 3 случай:
        else {
            // Идем до удяляемого объекта (т.е. слева от удаляемого объекта)
            for (int i = 0; i < indexU; i++) obj = obj->next;

            // Указатели на предыдущего и следующего пользователя соответственно от удаляемого пользователя.
            OBJ* prev_user = obj->prev;
            OBJ* next_user = obj->next;

            delete obj;
            
            next_user->prev = prev_user; // Следующий пользователь от удаляемого, теперь указывает на предыдущий от удаляемого.
            prev_user->next = next_user; // предыдущий пользователь от удаляемого, теперь указывает на следующий от удаляемого.
        }
    }

    void print_users() {
        /* Выводит в консоль всех пользователей списка */

        cout << "Users: " << len_list() << " count" << endl;
        OBJ* userP = startP; // Начинаем вывод от начал списка.
        int i = 1;
        // Идем до тех пор, пока список не закончится.
        while (userP != NULL) 
        {
            cout << "user[" << i++ << "]: " << userP->user.firstNameUser << " " << userP->user.secondNmeUser << endl;
            cout << "Email: " << userP->user.emailUser << " Index: " << userP->user.index << "\n" << endl;
            userP = userP->next; // перемещаем указатель на следующую структуру.
        }
        if (i == 1) cout << "List are empty" << endl;
    }

    
    void del_list() {
        // удаляет все элементы списка, пока начало не станет указателем на NULL.
        while (startP != NULL) del_user(0);
    }
    
};




int main()
{
    User user_01;
    cout << "What do you want?\na:(add user)\ns:(show users)\nd:(delete user)\nl:(delete list)" << endl;
    while (true)
    {
        char choose;
        
        cin >> choose;
        
        switch (choose)
        {
        case 'a':
            cout << "Position: ";
            int indexAdd;
            cin >> indexAdd;

            DATA_USER newUser;
            cout << "User Name: ";
            cin >> newUser.firstNameUser;

            cout << "Second Name: ";
            cin >> newUser.secondNmeUser;
            cout << "Email User: ";
            cin >> newUser.emailUser;
            cout << "Index User: ";
            cin >> newUser.index;

            user_01.add_user(indexAdd, newUser);
            break;
        case 's':
            user_01.print_users();
            break;
        case 'd':
            cout << "Enter the index: ";
            int index;
            cin >> index;
            user_01.del_user(index);
            break;
        case 'l':
            user_01.del_list();
            break;

        default:
            cout << "Enter some other letter\n";
            break;
        }
    }

    return 0;
}