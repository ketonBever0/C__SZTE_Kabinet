#include <stdio.h>


void fordit(char* s) {

  char *eleje = s;
  char *vege = s;

  while(*vege != '\0') {
    printf("%p %c\n", vege, *vege);
    ++vege;
  }

  --vege;
  printf("Eleje: %p %c\n", eleje, *eleje);
  printf("Vége: %p %c\n", vege, *vege);

  for (; eleje < vege; ++eleje, --vege)
  {
    int tmp = *eleje;
    *eleje = *vege;
    *vege = tmp;
  }
  
  // printf("Hossz: %ld\n", vege - eleje);

}


int main() {

  char str[100];
  scanf("%s", str);
  printf("%s\n", str);

  fordit(str);

  printf("%s\n", str);

  return 0;
}