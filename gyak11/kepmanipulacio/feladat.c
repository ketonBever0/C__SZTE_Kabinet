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

  int felbontas = szelesseg * magassag;

  int maxIntentizas;
  fscanf(fBe, "%d", &maxIntentizas);

  // char c;
  int *kep = malloc(sizeof(int) * felbontas);

  for (int i = 0; i < felbontas; i++)
  {
    fscanf(fBe, "%d", &kep[i]);
    // printf("%d\n", kep[i]);
  }

  int *ujKep = malloc(sizeof(int) * felbontas);

  switch (muvelet)
  {
  case 'N':
  {
    
    break;
  }
  case 'F':
  {

    break;
  }
  case 'V':
  {

    break;
  }
  case 'E':
  {

    break;
  }

  default:
    break;
  }

  fclose(fBe);

  FILE *fKi = fopen("./ki.txt", "w");
  fprintf(fKi, "asd\n");
  fclose(fKi);

  return 0;
}