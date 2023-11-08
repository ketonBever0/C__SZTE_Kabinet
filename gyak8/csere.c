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

  printf("A függvény előtt: x = %d, y = %d\n", x, y);
  csere(&x, &y);
  printf("A függvény után: x = %d, y = %d\n", x, y);

  return 0;
}
