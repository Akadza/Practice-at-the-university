#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int len(char* array) {
	int len = 0;
	for (int i = 0; i < array[i]; i++)
	{
		len++;
	}
	return len;
}

int maxValue(int a, int b) {
	if (a > b) return a;
	else return b;
}


double max_mass(double **array, int row) {
	double max = array[0][0];
	for (int i = 0; i < row; i++) {
		if (array[i][0] > max) max = array[i][0];
	}
	return max;
}
double min_mass(double** array, int row) {
	double min = array[0][0];
	for (int i = 0; i < row; i++)
	{
		if (min > array[i][0]) min = array[i][0];
	}
	return min;
}
int largest_sub(string a, string b);


int main()
{
	string line1;
	string line2;
	cout << "First line: ";
	getline(cin, line1);
	cout << "Second line: ";
	getline(cin, line2);
	cout << largest_sub(line1, line2);
	return 0;
}

int largest_sub(string a, string b) {
	int aLen = a.size();
	int bLen = b.size();
	
	int** array = new int* [aLen + 1];
	for (int i = 0; i < aLen + 1; i++) {
		array[i] = new int[bLen + 1];
	}

	for (int i = 0; i < aLen; i++) {
		for (int j = 0; j < bLen; j++) {
			array[i][j] = 0;
		}
	}

	for (int i = 1; i < aLen + 1; i++)
	{
		for (int j = 1; j < bLen + 1; j++)
		{
			if (a[i - 1] == b[j - 1]) array[i][j] = array[i - 1][j - 1] + 1;
			else array[i][j] = maxValue(array[i - 1][j], array[i][j - 1]);
		}
	}

	int result = array[aLen][bLen];

	for (int i = 0; i < bLen + 1; i++)
		delete[] array[i];
	delete[] array;

	return result;
	
}
