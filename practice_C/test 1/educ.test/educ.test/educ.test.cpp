#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int rub;
	double kurs, dollars;
	scanf("%d %lf", &rub, &kurs);
	dollars = rub * kurs;
	printf("%lf\n", dollars);
	return 0;
}
