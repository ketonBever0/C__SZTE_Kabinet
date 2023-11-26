#include <stdio.h>
#include <stdlib.h>

//  igaz - 1, hamis - 0
int vanKozelben(int sor, int oszlop, char **tomb, int i, int j, char keres, int maxTav)
{
    //  sorokon lépés
    for (int v = -maxTav; v < maxTav + 1; v++)
    {
        //  oszlopokon lépés
        for (int f = -maxTav; f < maxTav + 1; f++)
        {
            int vHely = i + v;
            int fHely = j + f;
            if (vHely >= 0 && vHely < sor && fHely >= 0 && fHely < oszlop)
            {
                if (tomb[vHely][fHely] == keres)
                {
                    /* printf("Innen: %d:%d itt: %d:%d\n", i + 1 , j + 1, vHely + 1, fHely + 1); */
                    return 1;
                }
            }
        }
    }

    return 0;
}

int main()
{

    FILE *fBe;
    fBe = fopen("./be.txt", "r");

    if (fBe == NULL)
    {
        printf("Nem olvashato a be.txt!\n");
        return -1;
    }

    int hegy, viz, homokvihar;

    if (fscanf(fBe, "%d %d %d", &hegy, &viz, &homokvihar) != 3)
    {
        printf("Nem olvashato az elso fejlec!\n");
        return -2;
    }

    int sor, oszlop;

    if (fscanf(fBe, "%d %d", &sor, &oszlop) != 2)
    {
        printf("Nem olvashato a masodik fejlec!\n");
        return -3;
    }

    char **szektor = malloc(sizeof(char *) * sor);

    for (int i = 0; i < sor; i++)
    {
        szektor[i] = malloc(sizeof(char) * (oszlop + 1));
        /* for (int j = 0; j < oszlop; j++)
        {
            fscanf(fBe, "%c", &szektor[i][j]);
        }
        szektor[i][oszlop] = '\0';
        printf("%s - %d\n", szektor[i], i); */
        fscanf(fBe, "%s", szektor[i]);
        /* printf("%s - %d\n", szektor[i], i); */
    }

    int alkalmasHelyek = 0;

    for (int i = 0; i < sor; i++)
    {
        //  2d tömb elemvizsgálat tesztelés
        /* for (int j = 0; j < oszlop; j++)
        {
            if (szektor[i][j] == 'A')
            {
                alkalmasHelyek++;
            }
        } */

        //  '0' - üres, '~' - víz, 'A' - hegy, 'X' - homokvihar
        for (int j = 0; j < oszlop; j++)
        {
            if (szektor[i][j] == 'X' || szektor[i][j] == 'A')
            {
                continue;
            }

            if (vanKozelben(sor, oszlop, szektor, i, j, 'X', homokvihar))
            {
                continue;
            }

            if (vanKozelben(sor, oszlop, szektor, i, j, 'A', hegy) &&
                vanKozelben(sor, oszlop, szektor, i, j, '~', viz))
            {
                alkalmasHelyek++;
            }
        }
    }

    /* printf("%d\n", alkalmasHelyek); */

    for (int i = 0; i < sor; i++)
    {
        free(szektor[i]);
    }
    free(szektor);

    fclose(fBe);

    FILE *fKi;
    fKi = fopen("./ki.txt", "w");

    if (fKi == NULL)
    {
        printf("Nem irhato a ki.txt!");
        return -4;
    }

    fprintf(fKi, "%d\n", alkalmasHelyek);

    fclose(fKi);

    return 0;
}
