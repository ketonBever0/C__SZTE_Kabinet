#include <stdio.h>
#include <stdlib.h>

int main()
{

  FILE *fBe = fopen("./be.txt", "r");

  char muvelet;
  fscanf(fBe, "%c", &muvelet);

  char tipus[3];
  fscanf(fBe, "%s", tipus);

  int szelesseg, magassag;
  fscanf(fBe, "%d %d", &szelesseg, &magassag);

  /* int felbontas = szelesseg * magassag; */

  int maxIntentizas;
  fscanf(fBe, "%d", &maxIntentizas);

  // char c;
  int **kep = malloc(sizeof(int *) * szelesseg);

  for (int i = 0; i < szelesseg; i++)
  {
    kep[i] = malloc(sizeof(int) * magassag);
    for (int j = 0; j < magassag; j++)
    {
      fscanf(fBe, "%d", &kep[i][j]);
    }
  }

  int **ujKep = malloc(sizeof(int *) * szelesseg);
  for (int i = 0; i < szelesseg; i++)
  {
    ujKep[i] = malloc(sizeof(int) * magassag);
  }

  FILE *fKi = fopen("./ki.txt", "w");
  fprintf(fKi, "P2\n%d %d\n%d\n", szelesseg, magassag, maxIntentizas);

  switch (muvelet)
  {
  case 'N': //  NEGATÍV
  {
    for (int i = 0; i < szelesseg; i++)
    {
      for (int j = 0; j < magassag; j++)
      {
        fprintf(fKi, "%d\n", maxIntentizas - kep[i][j]);
      }
    }

    break;
  }
  case 'F': //  FÜGGŐLEGES TÜKRÖZÉS
  {
    for (int i = 0; i < szelesseg; i++)
    {
      for (int j = 0; j < magassag; j++)
      {
        fprintf(fKi, "%d\n", kep[i][magassag - j - 1]);
      }
    }

    break;
  }
  case 'V': //  VÍZSZINTES TÜKRÖZÉS
  {
    for (int i = 0; i < szelesseg; i++)
    {
      for (int j = 0; j < magassag; j++)
      {
        fprintf(fKi, "%d\n", kep[szelesseg - i - 1][j]);
      }
    }

    break;
  }
  case 'E': //  ELMOSÁS
  {

    break;
  }

  default:
    break;
  }

  for (int i = 0; i < szelesseg; i++)
  {
    free(kep[i]);
    free(ujKep[i]);
  }

  free(kep);
  free(ujKep);

  fclose(fBe);
  fclose(fKi);

  return 0;
}