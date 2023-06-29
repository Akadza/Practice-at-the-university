#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define STR_LEN 50
#define COUNT 2

typedef struct {
  char name[20];
  char brand[20];
  char type[20];
  int weight;
  int price;
  char additives[50];
} chocolate;


int main() {
  chocolate choc[COUNT];
  int count_additives = 0;
  for (int i = 0; i < COUNT; i++) {
    scanf("%s %s %s %d %d %s", choc[i].name, choc[i].brand, choc[i].type, &choc[i].weight, &choc[i].price, choc[i].additives);
  }
  printf("\n\n");

  for (int i = 0; i < COUNT; i++) {
    printf("%s %s %s %d %d %s", choc[i].name, choc[i].brand, choc[i].type, choc[i].weight, choc[i].price, choc[i].additives);
  }
  printf("\n\n");

  int price;
  printf("Enter price: ");
  scanf("%d", &price);
  printf("\n\n");

  for (int i = 0; i < COUNT; i++) {
    if (price > choc[i].price) {
      printf("%s %s %s %d %d %s", choc[i].name, choc[i].brand, choc[i].type, choc[i].weight, choc[i].price, choc[i].additives);
    }
  }

  int min_weight = choc[0].weight;
  int index_min = 0;
  for (int i = 1; i < COUNT; i++) {
    if (min_weight > choc[i].price) {
      min_weight = choc[i].price;
      index_min = i;
    }

    printf("\n\nBrand = %s\n", choc[index_min].brand);
  }


  return 0;
}
