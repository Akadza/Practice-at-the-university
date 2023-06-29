#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define N 10

// см
typedef struct {
  double length;
  double width;
  double height;
} Demensions;

typedef struct {
  char name[100];
  double weight;
  int age; // кол-во месяцев
  int strenght; // количество ньютонов (прочность)
  char position[100];
  Demensions bone_demensions;
} Bone;

int main() {
  Bone human_bones[N];
  FILE *file1, *file2;
  file1 = fopen("HumanBones/bones.txt", "r");
  if (file1 == NULL) {
    printf("File was not found!\n");
    exit(1);
  }
  for (int i = 0; i < N; i++) {
    fscanf(file1, "%s %lf %d %d %s", human_bones[i].name, &human_bones[i].weight, &human_bones[i].age, &human_bones[i].strenght, human_bones[i].position);
  }
  fclose(file1);

  file2 = fopen("HumanBones/demensions.txt", "r");
  if (file2 == NULL) {
    printf("File was not found!\n");
    exit(1);
  }
  for (int i = 0; i < N; i++) {
    fscanf(file2, "%lf %lf %lf", &human_bones[i].bone_demensions.length, &human_bones[i].bone_demensions.width, &human_bones[i].bone_demensions.height);
  }
  fclose(file2);


  double averange_strength = 0;
  for (int i = 0; i < N; i++) {
    averange_strength += human_bones[i].strenght;
  }
  averange_strength /= N;
  printf("%.2lf\n\n", averange_strength);
  for (int i = 0; i < N; i++) {
    int f = human_bones[i].strenght;
    if (f >= averange_strength + averange_strength / 3) {
      printf("%s[%d]: %d\n", human_bones[i].name, i, human_bones[i].strenght);
    }
  }

  double human_bonesV, minV = human_bones[0].bone_demensions.length * human_bones[0].bone_demensions.width * human_bones[0].bone_demensions.height;
  for (int i = 0; i < N; i++) {
    human_bonesV = human_bones[i].bone_demensions.length * human_bones[i].bone_demensions.width * human_bones[i].bone_demensions.height;
    minV = (minV > human_bonesV) ? human_bonesV : minV;
  }
  printf("\nMin V = %.2lf\n", minV);


  return 0;
}
