/*
 * Szegedi TudomĂĄnyegyetem
 * Informatikai TanszĂŠkcsoport
 * SzoftverfejlesztĂŠs TanszĂŠk
 *
 * ProgramozĂĄs Alapjai
 */

#include <stdio.h>
int main()
{
  int elso = 0;
  int masodik = 0;
  int harmadik = 0;
  printf("L12: e= %d; m= %d; h= %d;\n", elso, masodik, harmadik);
  elso = 1;
  printf("L14: e= %d; m= %d; h= %d;\n", elso, masodik, harmadik);

  masodik = 2;
  printf("L17: e= %d; m= %d; h= %d;\n", elso, masodik, harmadik);

  printf("L19: e= %d; m= %d; h= %d;\n", elso, masodik, harmadik);

  harmadik = 3;
  printf("L22: e= %d; m= %d; h= %d;\n", elso, masodik, harmadik);

  printf("L24: e= %d; m= %d; h= %d;\n", elso, masodik, harmadik);
  return 0;
}