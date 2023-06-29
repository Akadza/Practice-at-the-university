#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

int main()
{
	srand(time(0));
	int x1, x2;
	double fln = 0,left = -100, rigth = 100;
	fln =  left + rand() * (rigth - left) / RAND_MAX;
	x1 = -53 + rand() % (44 + 53 + 1);
	x2 = -53 + rand() % (44 + 53 + 1);
	printf("%d, %d\n%lf\n\n", x1, x2, fln);
	
	FILE* file;
	file = fopen("C:\\Users\\byako\\Desktop\\test3.txt", "w");
	fprintf(file, " % d, % d\n % lf", x1, x2, fln);
	

	fclose(file);
	return 0;
}


