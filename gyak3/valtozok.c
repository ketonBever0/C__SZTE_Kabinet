#include <stdio.h>
#include <limits.h>

int main()
{

  int szam = 50;
  float lebegopontos1 = 5.4;
  float lebegopontos2 = 2.412357;
  char karakter = 'x';

  int szam2 = INT_MAX;

  printf("egész: %d\n", szam);
  printf("lebegőpontos1: %f\n", lebegopontos1);
  printf("lebegőpontos2: %f\n", lebegopontos2);
  printf("karakter: %c\n", karakter);
  printf("szam2: %d\n", szam2 + 1);

  return 0;
}