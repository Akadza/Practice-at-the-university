#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define N 10
#define STR_LEN 100

  typedef struct {
    char name_food[STR_LEN];
    int price_food;
    int calories_food;
    int popularity;
  } denominations;

  typedef struct {
    char name[STR_LEN];
    int average_price;
    int food_count;
    denominations *food;
  } food;

int main() {
  FILE *file, *file_den;
  food fast_food[N];
  if ((file = fopen("FastFood/FastFood.txt","r")) == NULL) {
    printf("File was not found!");
    exit(1);
  }


  for (int i = 0; i < N; i++) {
    fscanf(file, "%s %d %d", fast_food[i].name, &fast_food[i].average_price, &fast_food[i].food_count);
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
      fscanf(file_den, "%s %d %d %d", fast_food[i].food[j].name_food, &fast_food[i].food[j].price_food, &fast_food[i].food[j].calories_food, &fast_food[i].food[j].popularity);
    }
  }
  fclose(file_den);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < fast_food[i].food_count; j++) {
      if (fast_food[i].food[j].popularity > 75) {
        printf("%s: %s - %d%\n", fast_food[i].name, fast_food[i].food[j].name_food, fast_food[i].food[j].popularity);
      }
  }

}
  int k = 1;
  food key_food;
  while (k > 0) {
    k = 0;
    for (int i = 0; i < N - 1; i++) {
      if (fast_food[i].average_price > fast_food[i + 1].average_price) {
        // доделать сортировку структур
        k++;
        key_food = fast_food[i];
        fast_food[i] = fast_food[i + 1];
        fast_food[i + 1] = key_food;
      }
    }
  }

  printf("\n");
  for (int i = 0; i < N; i++) {
    printf("\n%5s %5d %5d\n", fast_food[i].name, fast_food[i].average_price, fast_food[i].food_count);
    for (int j = 0; j < fast_food[i].food_count; j++) {
      printf("%5s ", fast_food[i].food[j].name_food);
    }
  }


  for (int i = 0; i < N; i++) {
    free(fast_food[i].food);
  }
  return 0;
}
