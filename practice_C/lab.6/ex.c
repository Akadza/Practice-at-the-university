#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define N 10

  typedef struct {
    char name_food[100];
    int price_food;
    int calories_food;
    int popularity;
  } denominations;

  typedef struct {
    char name[100];
    int average_price;
    int food_count;
    denominations *food;
  } food;

int main() {
  FILE* file, *file_den;
  food fast_food[N];
  if ((file = fopen("FastFood/FastFood.txt","r")) == NULL) {
    printf("File was not found!");
    exit(1);
  }

  for (int i = 0; i < N; i++) {
    fscanf(file, "%s %d %d", fast_food[i].name, fast_food[i].average_price, fast_food[i].food_count);
  }
  fclose(file);

  for (int i = 0; i < N; i++) {
    fast_food[i].food = (denominations*)malloc(fast_food[i].food_count * sizeof(denominations));
  }

  if ((file_den = fopen("FastFood/denominations.txt","r")) == NULL) {
    printf("File was not found!");
    exit(1);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < fast_food[i].food_count; j++) {
      fscanf(file_den, "%s %d %d %d", fast_food[i].food[j].name_food, fast_food[i].food[j].price_food, fast_food[i].food[j].calories_food, fast_food[i].food[j].popularity);
    }
  }

  for (int i = 0; i < N; i++) {
    printf("%d\n", fast_food[i].average_price);
  }


  fclose(file_den);
  for (int i = 0; i < N; i++) {
    free(fast_food[i].food);
  }
  return 0;
}
