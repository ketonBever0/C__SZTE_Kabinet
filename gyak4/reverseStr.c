#include <stdio.h>

int strLen(char str[]) {
  int len = 0;
  while(str[len] != '\0') {
    len++;
  }
  return len;
}

void reverseStr(char str[]) {

  int start = 0;

  int len = strLen(str);

  char c;

  for (int i = 0, j = len - 1; i < j; i++, j--)
  {
    c = str[i];
    str[i] = str[i];
    str[j] = c;
    printf("%c", str[i]);
  }
  
  printf("%s", str);

  return len;

}


int main() {

  printf("%d\n", reverseStr("asd"));

  return 0;
}