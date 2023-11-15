#include <stdio.h>

int main() {

  int intArr[10];

  intArr[3] = 2;

  for (int i = 0; i < 10; i++)
  {
    printf("%d. érték: %d\n", i + 1, intArr[i]);
  }
  
  int intArr2[] = {1, 2, 3, 4, 5};

  for (int i = 0; i < 5; i++)
  {
    printf("%d. érték: %d\n", i + 1, intArr2[i]);
  }
  

  return 0;
}