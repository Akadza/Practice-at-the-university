#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Graph {
public:
    string fileName; // имя файла откуда берем значения вершин и их состояние.

    typedef struct obj_data {
        int n;
        vector<int> vertex; // вершина p
        vector<int> weight; // расстояние до вершины p.
        struct obj_data* nextVertex;
    } OBJ;

public:
    OBJ* tail = NULL, * head = NULL;
    void push(int n, vector<int> vertexs, vector<int> weight) {
        OBJ* ptr = new OBJ;
        ptr->n = n;
        ptr->vertex = vertexs;
        ptr->weight = weight;
        ptr->nextVertex = NULL;
        if (head == NULL) head = tail = ptr;
        else {
            tail->nextVertex = ptr;
            tail = ptr;
        }
    }

    // заполнение и создание из файла
    void fill() {
        string dataLine;
        vector<int> vertexArr, weightArr;
        int n, vertex, weight;

        ifstream fileDataGraph;
        fileDataGraph.open(fileName);
        if (fileDataGraph.is_open())
        {
            while (getline(fileDataGraph, dataLine))
            {
                istringstream ss(dataLine);
                ss >> n; // значение вершины.
                while (ss >> vertex) // соседи вершины.
                {
                    ss >> weight;
                    vertexArr.push_back(vertex);
                    weightArr.push_back(weight);
                }
                push(n, vertexArr, weightArr); // добавляем новую вершину с соседями.
                vertexArr.clear();
                weightArr.clear();
            }
        }
        else {
            cout << "File was not found!";
            return;
        }
        fileDataGraph.close();
    }

    // возращает индекс вершины, являющейся соседом, для прерыдущей вершины.
    int min_path(vector<int> weight) {
        int index = 0;
        int minWeight = weight[index];
        for (int i = 0; i < weight.size(); i++)
        {
            if (minWeight > weight[i])
            {
                minWeight = weight[i];
                index = i;
            }
        }
        return index;
    }

    void show() {
        OBJ* ptr = head;
        while (ptr != NULL)
        {
            cout << "V = " << ptr->n << endl;
            for (int i = 0; i < ptr->vertex.size(); i++)
            {
                cout << "neig: " << ptr->vertex[i] << " ";
                cout << "weig: " << ptr->weight[i] << endl;
            }
            cout << endl;
            ptr = ptr->nextVertex;
        } 
    }

    // возращает сумму пройденного пути из вершины n до p;
    int f_short_path(int start, int end) {
        OBJ* ptr = head;
        int lenPath = 0;

        if (head == NULL) return 0;

        // идем до тех пор, пока не найдем начальный город.
        while (ptr->n != start) {
            ptr = ptr->nextVertex;
        }

        int neigV = -1;
        while (ptr->n != end)
        {
            int index = min_path(ptr->weight); // индекс соседа вершины, с наименьшим весом.
            lenPath += ptr->weight[index]; // прибавляем вес к общей длине пути.
            // идем до следующей вершины до тех пор, пока не дойдем до выбранного соседа, с наименьшим весом.
            int someV = ptr->vertex[index];
            neigV = ptr->vertex[index];
            while (ptr->n != someV)
            {
                int V = ptr->n;
                ptr = ptr->nextVertex;
                if (neigV == end) return lenPath;
                if (ptr->nextVertex == NULL) {
                    cout << "vertex wasn't found! (or greedy algorithm does not work for her )" << endl;
                    return 0;
                }
            }

        }

        return lenPath;
    }

    Graph(string fileName) {
        this->fileName = fileName;
    }
};




int main()
{
    Graph graph{ "C:\\Users\\byako\\Desktop\\graph_2.txt" };
    graph.fill();
    graph.show();
    cout << graph.f_short_path(1, 8);

    return 0;
}