#include <stdio.h>
#include <stdlib.h>

void show(double* arr, int size) {
  for (int i = 0; i < 3; i++) {
    printf("%10.5lf", arr[i]);
  }
}

int main() {

  double array[3] = {1, 2, 3};
  show(array, 3);


  return 0;
}
