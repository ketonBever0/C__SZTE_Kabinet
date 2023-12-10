#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fBe = fopen("./be.txt", "r");

    if (fBe == NULL)
    {
        printf("Nem olvashato a be.txt!");
        return -1;
    }

    int kezdoSor, kezdoOszlop;
    if (fscanf(fBe, "%d,%d", &kezdoSor, &kezdoOszlop) != 2)
    {
        printf("Nem olvashatoak a kezdo koordinatak!");
        return -2;
    }

    /* char *fscan = malloc(sizeof(char)); */
    int tomb[20][20];

    /* int sor = 0, oszlop = 0; */

    /* char *teljes = malloc(sizeof(char) * 21); */

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            tomb[i][j] = -1;
        }
    }

    char temp;
    int vege = 0;

    /* Szkennelje be az első sor \n jelét */
    fscanf(fBe, "%c", &temp);

    int tombHossz = 0;

    for (int i = 0; i < 20; i++)
    {
        if (vege == 1)
        {
            break;
        }
        for (int j = 0; j < 20; j++)
        {
            /* fscanf(fBe, "%d", &tomb[i][j]); */
            int vanSzam = fscanf(fBe, "%d", &tomb[i][j]);
            /* printf("%d", vanSzam); */
            if (vanSzam == 0)
            {
                vege = 1;
            }
            fscanf(fBe, "%c", &temp);
            tombHossz++;
            /* printf("%d%c", tomb[i][j], temp); */
            if (temp == '-')
            {
                vege = 1;
                break;
            }
            if (temp == '\n')
            {
                break;
            }

            /* printf("%d\n", j); */
        }
        /* printf("\n"); */
    }

    /* for (int i = 1; i <= sor; i++)
    {
        for (int j = 1; j <= oszlop; j++)
        {
            printf("%5d", tomb[i][j]);
        }
        printf("\n");
    } */

    /* for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf("%3c", tomb[i][j]);
        }
        printf("\n");
    } */
    char *helyek = malloc(sizeof(char) * tombHossz);
    int helyIndex = tombHossz - 1;

    /* printf("eljut"); */
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (tomb[i][j] != -1)
            {
                helyek[helyIndex] = tomb[i][j];
                /* printf("%3d", helyek[helyIndex]); */
                helyIndex--;
            }
            /* printf("%4d", tomb[i][j]); */
        }
        /* printf("\n"); */
    }
    /* printf("\n"); */

    /* int tablaHely; */

    /* for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            tablaHely = i + j;
            tablaHely;
            printf("%c", tablaHely);
        }
    } */

    /* for (int i = 0; i < tombHossz; i++)
    {
        printf("%3c", helyek[i]);
    } */

    int jart[20][20];
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            jart[i][j] = 0;
        }
    }

    int sor = kezdoSor - 1, oszlop = kezdoOszlop - 1;

    helyIndex = tombHossz - 1;

    FILE *fKi = fopen("./ki.txt", "w");

    /* 0 - fel, 1 - balra, 2 - le, 3 - jobbra */
    int irany = 0;

    while (helyIndex > 0)
    {

        jart[sor][oszlop] = 1;

        for (int i = 0; i <= tombHossz; i++)
        {
            if (tomb[sor][oszlop] == helyek[i])
            {
                helyIndex--;
                fprintf(fKi, "%d", tomb[sor][oszlop]);
                if (helyIndex > 0)
                {
                    fprintf(fKi, ",");
                }
                /* printf("%d %d irany: %d - %d\n", sor + 1, oszlop + 1, irany, tomb[sor][oszlop]); */
                break;
            }
        }

        switch (irany)
        {
        case 0:
        {
            if (jart[sor - 1][oszlop] != 1)
            {
                sor--;
                if (jart[sor][oszlop - 1] != 1)
                {
                    irany = 1;
                }
            }
            break;
        }
        case 1:
        {
            if (jart[sor][oszlop - 1] != 1)
            {
                oszlop--;
                if (jart[sor + 1][oszlop] != 1)
                {
                    irany = 2;
                }
            }
            break;
        }
        case 2:
        {
            if (jart[sor + 1][oszlop] != 1)
            {
                sor++;
                if (jart[sor][oszlop + 1] != 1)
                {
                    irany = 3;
                }
            }
            break;
        }
        case 3:
        {
            if (jart[sor][oszlop + 1] != 1)
            {
                oszlop++;
                if (jart[sor - 1][oszlop] != 1)
                {
                    irany = 0;
                }
            }
            break;
        }
        default:
        {
            irany = 0;
            break;
        }
        }
    }

    fprintf(fKi, "\n");

    free(helyek);

    fclose(fBe);
    fclose(fKi);

    return 0;
}