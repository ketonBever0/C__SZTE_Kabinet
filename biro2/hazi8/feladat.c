#include <stdio.h>

int main()
{

    FILE *fBe;
    fBe = fopen("be.txt", "r");

    if (fBe == NULL)
    {
        printf("Nem olvashato a be.txt!");
        return -1;
    }

    int elso[2] = {0, 0};
    char sorok[100];
    int sor = 0;


    while(fgets(sorok, sizeof(sorok), fBe) == NULL) {
        printf("Nem lehet beolvasni a sort!");
        fclose(fBe);
        return -2;
    }

    if (sor == 0)
    {
        if (sscanf(sorok, "%d %d", &elso[0], &elso[1]) != 2 || elso[0] == 0 && elso[1] == 0)
        {
            printf("Nem lehet beolvasni a fejlecet!");
            fclose(fBe);
            return -3;
        }
    }
    printf("%d %d\n", elso[0], elso[1]);


    for (int i = 1; i < elso[0]; i++)
    {
        
    }
    



    fclose(fBe);

    return 0;
}