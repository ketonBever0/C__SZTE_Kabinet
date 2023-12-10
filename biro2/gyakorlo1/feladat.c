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

    //   A - Z
    //  65 - 90

    int forras, cel;
    char *szam = malloc(sizeof(char));

    if (fscanf(fBe, "%d %d %s", &forras, &cel, &szam) != 3)
    {
        printf("Nem olvashatoak a fajlbol az adatok!");
        return -2;
    }

    int szamhossz = 0;
    for (int i = 0; szam[i] != '\0'; i++)
    {
        szamhossz++;
    }


    for (int i = 0; szam[i] != '\0'; i++)
    {
        
    }
    



    FILE *fKi = fopen("./ki.txt", "w");


    fclose(fBe);
    fclose(fKi);

    return 0;
}