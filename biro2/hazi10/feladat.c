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

    char **sor = malloc(sizeof(char *));

    /* char *sor = malloc(sizeof(char)); */

    for (int i = 0;; i++)
    {
        sor[i] = malloc(sizeof(char));
        fscanf(fBe, "%c", sor[i]);
    }

    fclose(fBe);

    return 0;
}
