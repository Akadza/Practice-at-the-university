#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COL 5
#define ROW 10
#define RIGHT 150
#define LEFT -50

int main()
{
    int array[COL][ROW];
	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			array[i][j] = LEFT + rand() % (RIGHT - LEFT + 1);
		}
	}

	int value, k = 1;
	for (int i = 0; i < COL; i++)
	{
		while (k > 0) {
      k = 0;
      for (int j = 0; j < ROW; j++) {
        if (array[i][j] < array[i][j + 1]) {
          k++;
          value = array[i][j];
          array[i][j] = array[i][j + 1];
          array[i][j + 1] = value;
        }
      }
    }
	}



	for (int i = 0; i < COL; i++)
	{
		for (int j = 0; j < ROW; j++)
		{
			printf("%5d", array[i][j]);
		}

		printf("\n");
	}


	return 0;
}
/*for (int j = 0; j < ROW; j++)
{
  int indMax = j;
  for (int k = j + 1; k < ROW; k++)
  {
    if (array[i][k] > array[i][indMax])
    {
      indMax = k;
    }
  }
  value = array[i][j];
  array[i][j] = array[i][indMax];
  array[i][indMax] = value;
}*/
