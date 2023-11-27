#include <stdio.h>
#include <stdlib.h>

void kitomorit(char s[], char e[]) {
  for (int i = 0; s[i] != '\n'; i++)
  {
    char c = s[i];
    
    
  }
  
}

int main()
{

  FILE *fBe = fopen("./be.txt", "r");

  char str[101];

  // for (int i = 0; i < 100; i++)
  // {
  //   fscanf(fBe, "%c", str);
  // }

  int i = 0;
  char c = 'a';
  do
  {
    fscanf(fBe, "%c", &c);
    str[i] = c;
    i++;
  } while (c != '\0');

  fclose(fBe);

  FILE *fKi = fopen("./ki.txt", "w");

  fprintf(fKi, "%s", str);

  fclose(fKi);

  return 0;
}