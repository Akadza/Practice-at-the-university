#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	char array[10] = "hello";
	char copy[10] = "lorem";
	puts(array);
	strcpy(array, copy);
	puts(array);


	return 0;
}
