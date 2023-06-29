#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& array)
{
	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i] << " ";
	}

	std::cout << std::endl;
}

int main()
{
	
	std::vector<int> x = { 1, 22, 3 };
	std::vector<int> y = { 4, 55 };
	std::vector<int> v(x);
	print(v);
	std::copy(y.begin(), y.end(), std::back_inserter(v));
	print(v);
	v.clear();


	return 0;
}