#include <stdio.h>
#include <stdlib.h>

int *foglal_folytonos(int sor, int oszlop)
{

  int *t = malloc(sizeof(int) * sor * oszlop);

  for (int i = 0; i < sor * oszlop; i++)
  {
    t[i] = i + 1;
  }

  return t;
}

void kiir_folytonos(int *t, int sor, int oszlop)
{

  for (int i = 0; i < sor; i++)
  {
    for (int j = 0; j < oszlop; j++)
    {
      int k = i + j;

      printf("%3d", t[k]);
    }
    printf("\n");
  }
}

int **foglal_valos(int sor, int oszlop)
{

  int **t = malloc(sizeof(int *) * sor);

  for (int i = 0; i < sor; i++)
  {
    t[i] = malloc(sizeof(int) * oszlop);
  }

  return t;
}

void kiir_valos(int **t, int sor, int oszlop)
{
  int szam = 0;
  for (int i = 0; i < sor; i++)
  {
    for (int j = 0; j < oszlop; j++)
    {
      szam++;
      t[i][j] = szam;
      printf("%3d", t[i][j]);
    }
    printf("\n");
  }
}

void felszabadit_valos(int **t, int sor)
{

  /* int szam = 1; */

  for (int i = 0; i < sor; i++)
  {
    free(t[i]);
  }

  free(t);
}

int main()
{

  /* int *tomb = foglal_folytonos(2, 3);

  kiir_folytonos(tomb, 2, 3);

  free(tomb); */

  int **tomb2 = foglal_valos(3, 4);

  kiir_valos(tomb2, 3, 4);

  felszabadit_valos(tomb2, 3);

  /* kiir_valos(tomb2, 3, 4); */

  return 0;
}