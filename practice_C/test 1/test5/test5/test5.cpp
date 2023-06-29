#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main()
{
	FILE* secF;
	secF = fopen("C:\\Users\\byako\\Desktop\\forfive.txt", "r");

	if (secF == NULL) {
		printf("wrong file");
		exit(1);
	}
	float num1, num2;
	int j1, j2, j3;
	fscanf(secF, "%f%f%d%d%d", &num1, &num2, &j1, &j2, &j3);

	int maxj;
	float numsn = 0.0;
	// нужно вложенные тернарные операторы
	maxj = (j3 > ((j1 > j2) ? j1 : j2)) ? j3: ((j1 > j2) ? j1 : j2);
	numsn = (num1 > num2) ? num1 : num2;
	printf("%d, %f\n\n", maxj, numsn);
	fclose(secF);

	return 0;
}

