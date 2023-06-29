#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void eq(int);
int length(int);

int main()
{
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int rand_num = -5000 + rand() % (105000);
		eq(rand_num);
		printf("\n%d\n\n", rand_num);
	}
	return 0;
}

void eq(int num) {
	int res1 = 1, res2 = 1, i = length(num) - 1;

	while (num != 0)
	{
		int value = num / pow(10, i);
		num -= value * pow(10, i);
		if (value % 2 == 0)
			res1 *= value;
		else
			res2 *= value;
		i--;
	}

	printf("Res 1 = %d\n", res1);
	printf("Res 2 = %d", res2);
}

int length(int num) {
	int len_num = 0;

	while (num != 0)
	{
		num /= 10;
		len_num++;
	}
	return len_num;
}