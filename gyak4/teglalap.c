#include <stdio.h>

float kerulet(float a, float b) {

  return 2 * (a + b);

}

float terulet(float a, float b) {

  return a * b;

}

void teglalapSzamol() {
  
  float a, b;

  printf("Írja be a téglalap oldalainak méreteit szóközzel elválasztva: ");
  scanf("%f %f", &a, &b);

  // printf("%d %d\n", a, b);

  float ter = terulet(a, b);
  float ker = kerulet(a, b);

  printf("Kerulet: %.2f\nTerulet: %.2f\n", ker, ter);



}


int main() {

  teglalapSzamol();

  return 0;

}