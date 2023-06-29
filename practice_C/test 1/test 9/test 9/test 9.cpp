#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int count;
	int res1 = 0, res2 = 0;

	scanf("%d", &count); // количество вводимых

	for (int i = 0; i < count; i++)
	{
		int num = 0;
		scanf("%d", &num);
		res1 += (num / 10) * (pow(10, (-i + count - 1)));
		res2 += (num % 10) * (pow(10, (-i + count - 1)));
	}
	printf("Number first = %d\n", res1);
	printf("Number first = %d", res2);


	return 0;
}

