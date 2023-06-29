#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;



class Queue {

public:
    typedef struct obj_data {
        int n;
        struct obj_data* prevPtr;
    } OBJ;

public: OBJ* head = NULL, * tail = NULL;


public:
    bool empty() {
        if (head == NULL) return false;
        else return true;
    }

    // добавление элемента
    void push(int n) {
        OBJ* ptr = new OBJ;
        ptr->n = n;
        ptr->prevPtr = NULL;

        if (!empty()) head = tail = ptr;
        else {
            tail->prevPtr = ptr;
            tail = ptr;
        }
    }

    // добавляет в очередь вектор чисел.
    void addVertex(vector <int> array) {
        for (int i = 0; i < array.size(); i++)
        {
            push(array[i]);
        }
    }

    // выводит все элементы очереди.
    void show() {
        OBJ* ptr = new OBJ;
        ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->n << " ";
            ptr = ptr->prevPtr;
        }
    }

    // удаление элемента в голове.
    int pop() {
        if (head == NULL) return NULL;
        OBJ * temp;
        temp = head;
        int ptr = temp->n;
        head = head->prevPtr;
        delete temp;
        return ptr;
    }

    // очищение очереди.
    void free() {
        OBJ* ptr = new OBJ;
        while (ptr != NULL)
        {
            ptr = head->prevPtr;
            delete head;
            head = ptr;
        }
    }

    // возращает элемент в голове.
    int front() {
        return head->n;
    }

    // возращает элемент в хвосте.
    int rear() {
        return tail->n;
    }
};


class Graph {
public:
    string fileName; // имя файла откуда берем значения вершин и их состояние.

    // структура для представления вершин и указатели на следующие вершины. 
    typedef struct obj_data {
        int n;
        struct obj_data* prevVertex; // указатель на следующуюю вершину.
        vector<int> node; // динамический массив его соседей.

        /* примечание: Нам не обязетельно создавать новую последовательную структуру, если у нее нет соседей.
           Поэтому условно граф будет состоять только из тех элементов, у которых есть хотя бы один сосед.
           *-----*     *-----*
           |  n  |     |  n  |  arr - массив (a1, a2, .., aj) соседей числа n;
           | arr | --->| arr |
           *-----*     *-----*
        */
    } OBJ;
    

    // добавление новой структуры
    OBJ* head = NULL, * tail = NULL;
    // передаем значение n вершины и его соседей в виде целочисленного массива, с размером size;
    void push(int n, vector<int> array) {
        // иницилизируем новый объект
        OBJ* ptr = new OBJ;
        ptr->n = n;
        ptr->prevVertex = NULL;
        // добавляем в наш список
        if (head == NULL) head = tail = ptr;
        else {
            tail->prevVertex = ptr;
            tail = ptr;
        }
        // добавляем новых соседей для вершины :3
        for (int i = 0; i < array.size(); i++)
        {
            ptr->node.push_back(array[i]); 
        }
    }

    // заполнение графа данными из файла.
    void fill() {
        
        string dataLine;
        vector<int> array;
        int n, vertex;
        
        ifstream fileDataGraph;
        fileDataGraph.open(fileName);
        if (fileDataGraph.is_open())
        {
            while (getline(fileDataGraph, dataLine))
            {
                istringstream ss(dataLine);
                ss >> vertex; // значение вершины.
                while (ss >> n) // соседи вершины.
                {
                    array.push_back(n);
                }
                push(vertex, array);
                array.clear();
            }
        }
        else {
            cout << "File was not found!";
            return;
        }
        
        fileDataGraph.close();
    }

    // вывод графа.
    void show() {
        OBJ* ptr = head;
        while (ptr != NULL) {
            cout << "Vertex: " << ptr->n << endl;
            for (int i = 0; i < ptr->node.size(); i++)
            {   
                cout << i + 1 << ": " << ptr->node[i] << endl;
            }
            cout << endl;
            ptr = ptr->prevVertex;
        }
    }

    // возращает длину графа (~только главных вершин~)
    int len() {
        OBJ* ptr = head;
        int count = 0;
        while (ptr != NULL)
        {
            ptr = ptr->prevVertex;
            count++;
        }
        return count;
    }

    // возращает вектор соседей числа n в графе. ( ПО ЗНАЧЕНИЮ ВЕРШИНИ )
    vector<int> getV_vertex(int vertex_n) {
        OBJ* ptr = head;
        while (ptr != NULL)
        {
            if (ptr->n == vertex_n) return ptr->node;
            else ptr = ptr->prevVertex;
        }
        return vector<int>(); // пустой вектор если не нашли.
    }

    vector<int> getV_point(int n) {
        OBJ* ptr = head;
        for (int i = 0; i < n; i++) {
            ptr = ptr->prevVertex;
        }
        return ptr->node;
    }

    void ff(vector <int> array) {
        cout << endl;
        for (int i = 0; i < array.size(); i++)
        {
            cout << array[i] << " ";
        }
    }

    Graph(string fileName) {
        this->fileName = fileName;
    }
};


bool search(int n) {
    Graph graph{ "C:\\Users\\byako\\Desktop\\graph_1.txt" };
    graph.fill();
    graph.show();

    int valueVertex = 1;
    Queue queue; // текущее состояние очереди пустое.
    vector<int> checked; // храним проверенные числа.
    
    queue.addVertex(graph.getV_point(0));

    while (queue.empty())
    {
        int num = queue.pop();
        bool searched = true;
        for (int i = 0; i < checked.size(); i++) {
            if (num == checked[i]) {
                searched = false;
                break;
            }
        }
        if (searched && num == n)
        {
            cout << "Graph has " << num << " number" << endl;
            return true;
        }
        else {
            queue.addVertex(graph.getV_vertex(num));
            checked.push_back(num);
        }
        
    }


    return true;
}

int main()
{   
    search(11);
	return 0;
}