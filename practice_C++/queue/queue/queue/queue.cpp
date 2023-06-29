#include <iostream>

using namespace std;

typedef struct obj_data {
	int num;
	struct obj_data* nextN;
	struct obj_data* prevN;
} OBJ;

struct Queue {
	OBJ* head = NULL, * tail = NULL;

	// Возращает true, в случае если массив пустой.
	bool empty() {
		if (head == NULL) return true;
		else return false;
	}	

	// добавление элемента в начало очереди [хвост очереди]
	void push(int n) {
		OBJ* ptr = new OBJ;
		ptr->num = n;

		if (empty()) {
			head = tail = ptr;
		}

		else {
			ptr->nextN = tail;
			ptr->nextN->prevN = ptr;
			ptr->prevN = NULL;
			tail = ptr;
		}
	}

	// удаление элемента из начала очереди
	void pop() {
		OBJ* ptr = head;

		if (head == NULL) return;
		ptr->prevN->nextN = NULL;
		head = ptr->prevN;
		delete ptr;
	}

	// вывод всей очереди
	void showQ() {
		OBJ* ptr = tail;
		if (empty()) return;
		while (ptr != NULL)
		{
			cout << ptr->num << " ";
			ptr = ptr->nextN;
		}
	}

	// обращение к первому элеметну в очереди.
	int front() {
		return head->num;
	}
	
	// обращение к элементу в хвосте.
	int back() {
		return tail->num;
	}
};

int main()
{
	Queue queue;
	queue.pop();
	for (int i = 0; i < 10; i++)
	{
		queue.push(i + 1);
	}
	queue.pop();
	cout << "front = " << queue.front() << endl;
	cout << "back = " << queue.back() << endl;
	queue.showQ();

	return 0;
}

