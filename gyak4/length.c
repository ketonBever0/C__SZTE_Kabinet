#include <stdio.h>

int length(char s[]) {
  int i = 0;
  for (i; s[i] != '\0'; i++)
    {
      return i;
    }
}

int main() {

  char string[10];

  

  printf("Kérek egy szöveget: ");
  scanf("%[^\n]", &string);
  printf("%s\n", string);
  printf("string hossza: %d\n", length(string));

  return 0;
}