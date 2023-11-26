/*
 * Szegedi Tudományegyetem
 * Informatikai Tanszékcsoport
 * Szoftverfejlesztés Tanszék
 *
 * Programozás Alapjai
 */

#include <stdio.h>

void csere(int *x, int *y)
{

  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

int main()
{

  int x = 3, y = 5;
  int *p = &x, *q = &y;

  printf("A fuggveny elott: x = %d, y = %d\n", x, y);
  csere(&x, &y);
  printf("A fuggveny utan: x = %d, y = %d\n", x, y);

  return 0;
}
