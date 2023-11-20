#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fBe;
    fBe = fopen("be.txt", "r");

    if (fBe == NULL)
    {
        printf("Nem találhato a be.txt!");
        return -1;
    }

    int sorok = 0, oszlopok = 0;
    int fejlec = fscanf(fBe, "%d %d", &sorok, &oszlopok);
    /* printf("%d\n", fejlec); */

    if (fejlec != 2)
    {
        printf("Nem olvashato a fejlec!");
        return -2;
    }

    int **helyek = malloc(sizeof(int *) * sorok);

    for (int i = 0; i < sorok; i++)
    {
        helyek[i] = malloc(sizeof(int) * oszlopok);
        for (int j = 0; j < oszlopok; j++)
        {
            fscanf(fBe, "%d", &helyek[i][j]);
            /* printf("%3d", helyek[i][j]); */
        }
        /* printf("\n"); */
    }

    int raketak = 0;
    int robotHelye = 0; //  0 - 4 lehet és oszlopindexként lesz használva

    for (int i = 0; i < sorok; i++)
    {

        if (i == 0)
        {
            for (int j = 0; j < oszlopok; j++)
            {
                if (helyek[i][j] == 1)
                {
                    robotHelye = j;
                    break;
                }
            }
        }

        /* printf("%d: Robot: %d, Raketak: %d\n\n", i, robotHelye + 1, raketak);
        for (int j = 0; j < oszlopok; j++)
        {
            printf("%3d", helyek[i][j]);
        }
        printf("\n"); */

        int balMennyi = 0, jobbMennyi = 0;

        //  bal oldalt mennyi van
        for (int bal = 0; bal < robotHelye - 1; bal++)
        {
            if (helyek[i][bal] == 1)
            {
                raketak++;
                balMennyi++;
            }
        }

        //  jobb oldalt mennyi van
        for (int jobb = oszlopok; jobb > robotHelye + 1; jobb--)
        {
            if (helyek[i][jobb] == 1)
            {
                raketak++;
                jobbMennyi++;
            }
        }

        /* printf("%d %d\n", balMennyi, jobbMennyi); */

        //  ha kettő meteor közé kerül
        if (helyek[i][robotHelye] == 0 &&
            helyek[i][robotHelye - 1] == 1 &&
            helyek[i][robotHelye + 1] == 1)
        {
            raketak += 2;
            continue;
        }

        //  ha a jelenlegi helyéről el tud kapni
        if (helyek[i][robotHelye] == 1 &&
            helyek[i][robotHelye - 1] == 1 &&
            helyek[i][robotHelye + 1] == 1)
        {
            raketak += 2;
            continue;
        }
        else if (helyek[i][robotHelye] == 1 &&
                 helyek[i][robotHelye - 1] == 1)
        {
            raketak++;
            continue;
        }
        else if (helyek[i][robotHelye] == 1 &&
                 helyek[i][robotHelye + 1] == 1)
        {
            raketak++;
            continue;
        }

        //  ha balról el tud kapni
        if (helyek[i][robotHelye - 1] == 1)
        {
            robotHelye--;
            continue;
        }

        //  ha jobbról el tud kapni
        if (helyek[i][robotHelye + 1] == 1)
        {
            robotHelye++;
            continue;
        }

        //  ha sehonnan sem tud elkapni
        if (helyek[i][robotHelye] == 0)
        {
            if (balMennyi > jobbMennyi)
            {
                robotHelye--;
            }
            else if (jobbMennyi > balMennyi)
            {
                robotHelye++;
            }
        }
    }

    /* printf("%d: Robot: %d, Raketak: %d\n", sorok, robotHelye + 1, raketak); */

    for (int i = 0; i < sorok; i++)
    {
        free(helyek[i]);
    }

    free(helyek);

    fclose(fBe);

    FILE *fKi;
    fKi = fopen("ki.txt", "w");

    if (fKi == NULL)
    {
        printf("Nem nyithato meg az irando fajl!");
        return -3;
    }

    if (fprintf(fKi, "%d\n", raketak) == 0)
    {
        printf("Nem irhato a fajl!");
        return -4;
    }

    fclose(fKi);

    return 0;
}