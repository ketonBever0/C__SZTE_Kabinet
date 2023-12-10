#include <stdio.h>
#include <stdlib.h>

int main()
{

    int meret = 5;
    int novel = 1;

    int **szam = malloc(sizeof(int *) * meret);
    for (int i = 0; i < meret; i++)
    {
        szam[i] = malloc(sizeof(int) * meret);
        for (int j = 0; j < meret; j++)
        {
            szam[i][j] = novel;
            printf("%3d", szam[i][j]);
            novel++;
        }
        printf("\n");
    }

    printf("\nVizszintes tukrozes\n");
    for (int i = 0; i < meret; i++)
    {
        for (int j = 0; j < meret; j++)
        {
            printf("%3d", szam[meret - i - 1][j]);
        }
        printf("\n");
    }

    printf("\nFuggoleges tukrozes\n");
    for (int i = 0; i < meret; i++)
    {
        for (int j = 0; j < meret; j++)
        {
            printf("%3d", szam[i][meret - j - 1]);
        }
        printf("\n");
    }

    return 0;
}