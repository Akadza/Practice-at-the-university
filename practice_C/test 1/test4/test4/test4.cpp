#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main()
{
	FILE* file;
	file = fopen("C:\\Users\\byako\\Desktop\\fortest.txt", "r");
	if (file == NULL) {
		printf("wrong!");
		exit(1);
	}
	int k1, k2, k3, k4, k5;
	float p1, p2, p3;

	fscanf(file, "%d%d%d%d%d%f%f%f", &k1, &k2, &k3, &k4, &k5, &p1, &p2, &p3);
	printf("%d, %d, %d, %d, %d, %0.3f, %0.3f, %0.3f", k1, k2, k3, k4, k5, p1, p2, p3);
	int sumx;
	float sump;
	sumx = k1 + k2 + k3 + k4 + k5;
	sump = p1 + p2 + p3;
	printf("\n%d\n%f\n\n", sumx, sump);

	fclose(file);

	return 0;
}
