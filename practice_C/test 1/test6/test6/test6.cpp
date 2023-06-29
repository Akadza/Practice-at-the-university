#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

int main()
{// нужные if else
	setlocale(LC_ALL, "Russian");
	char l;
	scanf("%c", &l);
	if (l == 'A' || l == 'a' || l == 'e' || l == 'E' || l == 'i' || l == 'I' || l == 'O' || l == 'o' || l == 'U' || l == 'u' || l == 'Y', l == 'y')
	{
		printf("Gl l");
	}
	else {
		printf("Cgl l");
	}

	return 0;
}
