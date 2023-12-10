#include <stdio.h>
#include <stdlib.h>

int main()
{

    int sor = 5, oszlop = 10;
    int novel = 1;

    int **szam = malloc(sizeof(int *) * sor);
    for (int i = 0; i < sor; i++)
    {
        szam[i] = malloc(sizeof(int) * oszlop);
        for (int j = 0; j < oszlop; j++)
        {
            szam[i][j] = novel;
            printf("%3d", szam[i][j]);
            novel++;
        }
        printf("\n");
    }

    printf("\nVizszintes tukrozes\n");
    for (int i = 0; i < sor; i++)
    {
        for (int j = 0; j < oszlop; j++)
        {
            printf("%3d", szam[sor - i - 1][j]);
        }
        printf("\n");
    }

    printf("\nFuggoleges tukrozes\n");
    for (int i = 0; i < sor; i++)
    {
        for (int j = 0; j < oszlop; j++)
        {
            printf("%3d", szam[i][oszlop - j - 1]);
        }
        printf("\n");
    }

    return 0;
}