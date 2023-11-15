#include <stdio.h>

int main() {
  
  char string[10] = {'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I', 'J', 'K'};
  
  for (int i = 0; i < 10; i++)
  {
    printf("%c", string[i]);
  }
  
  printf("\n%s\n", string);
  
  return 0;
}