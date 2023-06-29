#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Node {
public:
    int key; // ключ, по которому мы и будем делать все операции. (ключ работает по правилу б.дерева поиска)
    int value; // значение данного ключа. (свободное значение)
    Node* left = nullptr;
    Node* right = nullptr;

    Node(int p_value, int p_key) {
        value = p_value;
        key = p_key;
    }
};

class Tree {
public:
    Node* root = nullptr; // вершина дерева.

public:
    /* поиск элемента по всему дереву
       возращает указатель на ноду элемента. */
    Node* find_v(Node* node, int key) {
        if (node == nullptr) return nullptr;
        if (node->key == key) return node;
        return (key < node->key) ? find_v(node->left, key) : find_v(node->right, key);
    }

    // вставка элемента.
    void add(Node* node, int key, int value, Node* parent = nullptr) {
        if (root == nullptr) {
            root = new Node(key, value);
        }
        else if (key < node->key)
        {
            if (node->left == nullptr) node->left = new Node(key, value);
            else add(node->left, key, value, root);
        }
        else if (key >= node->key) {
            if (node->right == nullptr) node->right = new Node(key, value);
            else add(node->right, key, value, root);
        }
    }
    
    //возращает указатель на максимальный элемент дерева.
    Node* max(Node* node) {
        if (node == nullptr) return nullptr;
        if (node->right == nullptr) return node;
        return max(node->right);
    }
    // возращает указатель на минимальный элемент дерева.
    Node* min(Node* node) {
        if (node == nullptr) return nullptr;
        if (node->left == nullptr) return node;
        return min(node->left);
    }

    Node* del_v(Node* node, int key) {  
        if (node == nullptr) return nullptr;
        else if (key < node->key) node->left = del_v(node->left, key);
        else if (key > node->key) node->right = del_v(node->right, key);
        else {
            // Найден элемент, который нужно удалить
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                node = nullptr;
            }
            else if (node->left == nullptr) {
                Node* temp = node;
                node = node->right;
                delete temp;
                temp = nullptr;
            } 
            else if (node->right == nullptr) {
                Node* temp = node;
                node = node->left;
                delete temp;
                temp = nullptr;
            }
            else {
                // ищем минимальный элемент в правом поддереве.
                Node* temp = min(node->right);
                node->key = temp->key;
                node->value = temp->value;
                node->right = del_v(node->right, temp->key);
            }
        }
        return node;
    }

    // выведем все элементы дерева по их возрастанию.
    void show_tree(Node* node) {
        if (node == nullptr) return;
        show_tree(node->left);
        cout << node->key << " ";
        show_tree(node->right);
    }

    void deleteNode(Node* node) {
        if (node == nullptr) return;
        deleteNode(node->left);
        deleteNode(node->right);
        delete node;
    }

    // удаляет все элементы поддерева.
    void clear_tree() {
        deleteNode(root);
        root = nullptr;
    }
};


// заполнение массивы числами из файла.
void read_file(vector<double>& arr) {
    ifstream data("data.txt");
    int val;

    if (data.is_open())
    {
        while (data >> val)
            arr.push_back(val);
    }
    else {
        cout << "File wasn't found!";
        return;
    }
}


int main()
{
    vector<double> arr;
    read_file(arr);

    Tree tree;

    // запишем данные
    for (int i = 0; i < arr.size(); i++)
    {
        tree.add(tree.root, arr[i], arr[i]);
    }
    cout << "Tree: " << endl;
    tree.show_tree(tree.root);
    cout << endl;
    tree.del_v(tree.root, 5);
    tree.del_v(tree.root, 6);
    tree.del_v(tree.root, -102);
    tree.del_v(tree.root, -73);
    tree.del_v(tree.root, 67);

    cout << "Tree: " << endl;
    tree.show_tree(tree.root);
    cout << endl;

    tree.clear_tree();
    cout << "Tree: " << endl;
    tree.show_tree(tree.root);

    tree.add(tree.root, 15, 853);
    tree.add(tree.root, 18, 8);
    tree.add(tree.root, 19, 53);
    cout << "Tree: " << endl;
    tree.show_tree(tree.root);

    return 0;
}

