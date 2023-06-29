#include <iostream>

using namespace std;

int fac(int n, int res) {
	if (n == 1 || n == 0) return res;
	return fac(n - 1, res * n);
}

int nod(int a, int b) {
	if (a % b == 0) return b;
	nod(b, a % b);
}

int main()
{
	cout << fac(4, 1) << endl;
	cout << nod(18, 45) << endl;
}
