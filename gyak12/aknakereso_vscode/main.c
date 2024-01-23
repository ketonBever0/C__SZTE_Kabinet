#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define srand AZ_SRAND_NEM_SZEREPELHET_A_PROGRAMBAN

typedef struct
{
    int x;
    int y;
} Koordinata;

/****************************************************************
 *                                                               *
 *           EZT A FÜGGVÉNYT KELL MEGVALÓSÍTANI!                 *
 *                                                               *
 *****************************************************************/
/* A feladat a lenti függvény megvalósítása. A függvénynek egy lépést kell tennie az aknakeresőben,
 * lehetőleg egy olyan mezőt kéne kiválasztani, ahol nincs akna. A függvény visszatérési értéke egy Koordináta,
 * amely leírja a választott mezőt (x és y változójában). Garantálható, hogy mindig lesz legalább egy mező,
 * amelyen nem található akna. A függvény használhat random szám generátort, de az srand függvény nem használható.
 * A függvény paraméterei:
 * N: ennyi sorból áll az aknamező
 * M: ennyi oszlopból áll az aknamező
 * aknak: ennyi akna van összesen az aknamezőn
 * mezo: 2D-s, inteket tároló tömb, amely leírja az aknamezőt az alábbiak szerint:
 * - nemnegatív szám (0 és 8 között) jelzi, hogy ezzel a mezővel ennyi szomszédos akna van
 * - -1 jelzi, hogy nem ismert, hogy a mezővel hány szomszédos akna van
 *
 * fordításhoz és futtatáshoz, illetve a paraméterezéshez az alábbi linken találsz segítséget:
 * www.inf.u-szeged.hu/~gmark/game
 */

// typedef struct
// {
//     int x, y;
//     int ertek;
// } Hely;

Koordinata lepes(int N, int M, int aknak, int **mezo)
{
#define nev "Kurucz László"
#define neptun "Z5RFY1"
#define alias "Karoly Boss"

    Koordinata k;
    // printf("Értékek: %d %d %d\n", N, M, aknak);
    // itt kéne kiszámítani a k.x és k.y értékét
    // k.x = rand() % N;
    // k.y = rand() % M;

    k.x = 0;
    k.y = 0;

    int aknakMost = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mezo[i][j] == -1)
            {
                k.x = i;
                k.y = j;
                // mezo[i][j] = rand() % 9;
                if (i == 0 || i == 1)
                {
                    mezo[i][j] = 0;
                }
                if (aknak > 0)
                {
                    mezo[i][j] = rand() % 9;
                    aknak--;
                }
                else
                {
                    mezo[i][j] = 0;
                }
            }
        }
    }

    // Hely hely;
    int max = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {

            if (mezo[i][j] > max)
            {
                k.x = i;
                k.y = j;
                max = mezo[i][j];
                if (j == 0)
                {
                    continue;
                }

                // for (int s = -1; s < 2; s++)
                // {
                //     for (int o = -1; o < 2; o++)
                //     {
                //         if (i == s && j == o)
                //         {
                //             continue;
                //         }



                //     }
                // }
            }
        }
    }

    return k;
}

/****************************************************************
 *                                                               *
 *                         FÜGGVÉNY VÉGE                         *
 *                                                               *
 *****************************************************************/

void processInput()
{
    int N;
    int M;
    int aknak;
    int **mezo;

    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &aknak);

    mezo = (int **)malloc(N * sizeof(int *));

    int i, j;
    for (i = 0; i < N; i++)
    {
        mezo[i] = (int *)malloc(M * sizeof(int));
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &mezo[i][j]);
        }
    }

    Koordinata k = lepes(N, M, aknak, mezo);
    printf("%d\n%d\n", k.x, k.y);
}

int main()
{
    char line[100];

    scanf("%s", line);

    if (!strcmp(line, "PLAYERDATA"))
    {
        printf("%s\n%s\n%s\n", nev, neptun, alias);
    }
    else if (!strcmp(line, "NORMAL"))
    {
        processInput();
    }

    return 0;
}