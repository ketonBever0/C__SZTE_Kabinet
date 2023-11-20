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

        printf("%d: Robot: %d, Raketak: %d\n\n", i, robotHelye + 1, raketak);
        for (int j = 0; j < oszlopok; j++)
        {
            printf("%3d", helyek[i][j]);
        }
        printf("\n");

        for (int j = 0; j < oszlopok; j++)
        {
            if (helyek[i][robotHelye] == 0 && helyek[i][robotHelye - 1] == 0 && helyek[i][robotHelye + 1] == 0)
            {
                if (helyek[i][robotHelye - j] == 1)
                {
                    raketak++;
                }
                if (helyek[i][robotHelye + j] == 1)
                {
                    raketak++;
                }
            }
        }

        //  ROBOT MOZGÁS
        //  Maradjon helyben
        if (helyek[i][robotHelye] == 1 ||                                       //  nála
            (helyek[i][robotHelye - 1] == 1 && helyek[i][robotHelye] == 1) ||   //  nála és balra
            (helyek[i][robotHelye + 1] == 1 && helyek[i][robotHelye] == 1) ||   //  nála és jobbra
            (helyek[i][robotHelye - 1] == 1 && helyek[i][robotHelye + 1] == 1)) //  balra és jobbra
        {
            //  csak bal és jobb esetben
            if (helyek[i][robotHelye - 1] == 1 && helyek[i][robotHelye + 1] == 1)
            {
                raketak += 2;
            }
            continue;
        }

        //  Ha nem talál a közelében meteort, merre induljon el
        if (helyek[i][robotHelye] == 0 && helyek[i][robotHelye - 1] == 0 && helyek[i][robotHelye + 1] == 0)
        {
            int jobbraLevok = 0, balraLevok = 0;
            for (int j = 0; j < oszlopok; j++)
            {
                if (helyek[i][j] == 1)
                {
                    if (j < robotHelye)
                    {
                        /* printf("balra van\n"); */
                        balraLevok++;
                    }
                    else if (j > robotHelye)
                    {
                        /* printf("jobbra van\n"); */
                        jobbraLevok++;
                    }
                }
            }

            if (balraLevok > jobbraLevok)
            {
                /* printf("bal\n"); */
                robotHelye--;
            }
            else if (jobbraLevok > balraLevok)
            {
                /* printf("jobb\n"); */
                robotHelye++;
            }
            /* printf("bal: %d, jobb: %d\n", balraLevok, jobbraLevok); */
            /* continue; */
        }


    }

    printf("%d: Robot: %d, Raketak: %d\n", sorok, robotHelye, raketak);

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

//  előző próba rakétanövelésre magamnak
/* if (helyek[i][robotHelye - 4] == 1)
{
    raketak++;
}
if (helyek[i][robotHelye + 4] == 1)
{
    raketak++;
}
if (helyek[i][robotHelye - 3] == 1)
{
    raketak++;
}
if (helyek[i][robotHelye + 3] == 1)
{
    raketak++;
}
if (helyek[i][robotHelye - 2] == 1)
{
    raketak++;
}
if (helyek[i][robotHelye + 2] == 1)
{
    raketak++;
} */

//  robotmozgás
/* if (helyek[i][robotHelye - 1] == 1 ||
    helyek[i][robotHelye - 2] == 1 ||
    helyek[i][robotHelye - 3] == 1 ||
    helyek[i][robotHelye - 4] == 1)
{
    robotHelye--;
}
else if (helyek[i][robotHelye + 1] == 1 ||
         helyek[i][robotHelye + 2] == 1 ||
         helyek[i][robotHelye + 3] == 1 ||
         helyek[i][robotHelye + 4] == 1)
{
    robotHelye++;
} */