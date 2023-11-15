#include <stdio.h>

int main() {

  int num;
  scanf("%d", &num);
  
  if (num % 2 == 0) printf("- páros szám\n");
  else printf("- páratlan szám\n");

  if(num > 0) printf("- pozitív\n");
  else if (num == 0)("- nulla\n");
  else if (num < 0) printf("- negatív\n");

  return 0;
}