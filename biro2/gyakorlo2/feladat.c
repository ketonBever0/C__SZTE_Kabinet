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

    int muvelet, oszlop;
    fscanf(fBe, "%d %d", &muvelet, &oszlop);

    /* printf("%d %d", muvelet, oszlop); */

    int *sorrend = malloc(sizeof(int) * oszlop);
    for (int i = 0; i < oszlop; i++)
    {
        fscanf(fBe, "%d", &sorrend[i]);
        /* printf("%3d", sor[i]); */
    }
    /* printf("\n"); */

    /* free(sor); */

    char *str = malloc(sizeof(char) * 200);
    fscanf(fBe, "%s", str);

    int strLen = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        strLen++;
    }

    int sor = (strLen / oszlop);
    int k = 0;
    char **tabla = malloc(sizeof(char *) * sor);

    FILE *fKi = fopen("./ki.txt", "w");

    switch (muvelet)
    {
    case 1: //  kódolás
    {

        for (int i = 0; i < sor; i++)
        {
            /* printf("%c", str[i]); */
            tabla[i] = malloc(sizeof(char) * oszlop);
            for (int j = 0; j < oszlop; j++)
            {
                tabla[i][j] = str[k];
                k++;
                /* printf("%3c", tabla[i][j]); */
            }
            /* printf("\n"); */
        }

        for (int i = 0; i < oszlop; i++)
        {
            for (int j = 0; j < sor; j++)
            {
                /* printf("%c", tabla[j][sorrend[i - 1]]); */
                fprintf(fKi, "%c", tabla[j][sorrend[i] - 1]);
            }
        }
        /* printf("\n"); */

        break;
    }
    case 2: //  dekódolás
    {

        for (int i = 0; i < sor; i++)
        {
            tabla[i] = malloc(sizeof(char) * oszlop);
        }

        for (int i = 0; i < oszlop; i++)
        {
            for (int j = 0; j < sor; j++)
            {
                tabla[j][sorrend[i] - 1] = str[k];
                k++;
                /* printf("%3c", tabla[j][i]); */
            }
            /* printf("\n"); */
        }

        for (int i = 0; i < sor; i++)
        {
            for (int j = 0; j < oszlop; j++)
            {
                /* printf("%3c", tabla[i][j]); */
                fprintf(fKi, "%c", tabla[i][j]);
                /* printf("s%d o%d\n", i, j); */
            }
            /* printf("\n"); */
        }
        fprintf(fKi, "\n");

        break;
    }
    default:
    {
        printf("Hiba!\n");
        return -2;
        break;
    }
    }

    free(sorrend);
    free(str);

    for (int i = 0; i < oszlop; i++)
    {
        free(tabla[i]);
    }
    free(tabla);

    fclose(fBe);
    fclose(fKi);

    return 0;
}