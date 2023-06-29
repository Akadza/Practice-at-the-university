#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define N 10
#define LEFT -1
#define RIGHT 1

/*Для массива структур из 10ти элементов вывести на экран самые популярные операционные системы
(популярность более 60%). Вывести на экран создателей операционных систем с популярностью не ниже средней.
Массив структур заполнить из файла.*/

typedef struct {
  char name[100];
  int releaseData;
  char creator[100];
  double popularity;
} OSystem;

int main() {
  FILE* file;
  OSystem o_system[N];
  if ((file = fopen("Osystem/Osystem.txt","r")) == NULL) {
    printf("File was not found!");
    exit(1);
  }

  // 1
  for (int i = 0; i < N; i++) {
    fscanf(file, "%s %d %s %lf", &o_system[i].name, &o_system[i].releaseData, &o_system[i].creator, &o_system[i].popularity);
  }
  fclose(file);
  printf("Table:\n");
  printf("%10s %20s %20s %20s\n", "name", "realeaseData", "creator", "popularity");

  for (int i = 0; i < N; i++) {
    if (o_system[i].popularity > 60) {
      printf("%10s %20d %20s %19.2lf%\n", o_system[i].name, o_system[i].releaseData, o_system[i].creator, o_system[i].popularity);
    }
  }

  printf("\n\n");
  printf("Table:\n");
  printf("%10s %20s\n", "name", "popularity");

  double average = 0.0;
  for (int i = 0; i < N; i++) {
    average += o_system[i].popularity;
  }

  for (int i = 0; i < N; i++) {
    if (o_system[i].popularity >= average / N) {
      printf("%10s %20.2lf\n", o_system[i].name, o_system[i].popularity);
    }
  }

  return 0;
}
