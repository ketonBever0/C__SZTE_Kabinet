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

  int **kep = malloc(sizeof(int *) * magassag);
  for (int i = 0; i < magassag; i++)
  {
    kep[i] = malloc(sizeof(int) * szelesseg);
    for (int j = 0; j < szelesseg; j++)
    {
      fscanf(fBe, "%d", &kep[i][j]);
    }
  }

  /* int **ujKep = malloc(sizeof(int *) * szelesseg);
  for (int i = 0; i < szelesseg; i++)
  {
    ujKep[i] = malloc(sizeof(int) * magassag);
  } */

  FILE *fKi = fopen("./ki.txt", "w");
  fprintf(fKi, "P2\n%d %d\n%d\n", szelesseg, magassag, maxIntentizas);

  switch (muvelet)
  {
  case 'N': //  NEGATÍV
  {
    for (int i = 0; i < magassag; i++)
    {
      for (int j = 0; j < szelesseg; j++)
      {
        fprintf(fKi, "%d\n", maxIntentizas - kep[i][j]);
      }
    }

    break;
  }
  case 'F': //  FÜGGŐLEGES TÜKRÖZÉS
  {
    for (int i = 0; i < magassag; i++)
    {
      for (int j = 0; j < szelesseg; j++)
      {
        fprintf(fKi, "%d\n", kep[i][szelesseg - j - 1]);
      }
    }

    break;
  }
  case 'V': //  VÍZSZINTES TÜKRÖZÉS
  {
    for (int i = 0; i < magassag; i++)
    {
      for (int j = 0; j < szelesseg; j++)
      {
        fprintf(fKi, "%d\n", kep[magassag - i - 1][j]);
      }
    }

    break;
  }
  case 'E': //  ELMOSÁS
  {

    for (int i = 0; i < magassag; i++)
    {
      for (int j = 0; j < szelesseg; j++)
      {
        int f = i - 5, fVeg = i + 5, v = j - 5, vVeg = j + 5;

        while (f < 0)
        {
          f++;
        }

        while (fVeg >= magassag)
        {
          fVeg--;
          /* printf("%d\n", f); */
        }

        while (v < 0)
        {
          v++;
        }

        while (vVeg >= szelesseg)
        {
          vVeg--;
        }

        /* printf("%3d %3d\n", i, j); */
        /* printf("itt\n"); */
        int osszeg = 0, mennyi = 0;
        for (; f < fVeg; f++)
        {
          for (; v < vVeg; v++)
          {
            mennyi++;
            osszeg += kep[f][v];
          }
        }

        fprintf(fKi, "%d\n", osszeg / mennyi);
      }
    }

    break;
  }

  default:
    break;
  }

  for (int i = 0; i < szelesseg; i++)
  {
    free(kep[i]);
    /* free(ujKep[i]); */
  }

  free(kep);
  /* free(ujKep); */

  fclose(fBe);
  fclose(fKi);

  return 0;
}