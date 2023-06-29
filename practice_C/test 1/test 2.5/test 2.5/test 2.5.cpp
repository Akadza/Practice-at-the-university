#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
	double y, x = -9.3;
	double res1 = 0.0, res2 = 0.0;
	printf("OX: ");
	while (x != 15.2)
	{
		printf("%10.1lf", x);
		x += 3.5;
	}
	x = -9.3;
	printf("\nOY: ");
	while (x != 15.2)
	{
		y = 4 * pow(x, 3) - 8 * pow(x, 2) + 5 * x + 1;
		printf("%10.3lf", y);
		x += 3.5;
		if (y > 0.0)
		{
			res1 += y;
		}
		else
		{
			res2 += (-y);
		}
	}
	printf("\n");
	if (res1 > res2) {
		printf("Res 1 > Res 2 : Res 1 = %lf", res1);
	}
	else
	{
		printf("Res 2 > Res 1 : Res 2 = %lf", res2);
	}
	


    return 0;
}


