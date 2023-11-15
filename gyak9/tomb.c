#include <stdio.h>

#define N 5

void feltolt(int t[]) {

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &t[i]);
  }
  

}

void kiir(int t[]) {

  for (int i = 0; i < N; i++)
  {
    printf("%d: %d [%p]\n", i, t[i], &t[i]);
  }
  
}

void kiir2(int *p) {
  printf("Pointer kiir:\n");
  // for (int i = 0; i < N; i++)
  // {
  //   printf("%d: %p\n", i, *(p + i), (p + 1));
  // }

  for (int i = 0; i < N; i++, p++)
  {
    printf("%d: %d [%p]\n", i, *p, p);
  }
  
  
}

int main() {

  int t[N];

  feltolt(t);
  
  kiir(t);
  kiir2(t);

  return 0;

}