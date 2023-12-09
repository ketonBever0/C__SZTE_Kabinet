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

    char *tomb = malloc(sizeof(int));

    /* char *sor = malloc(sizeof(char)); */

    int vege = 0;
    int arrLen = 0;
    for (int i = 0; vege == 0; i++)
    {
        char *sor = malloc(sizeof(char));
        fscanf(fBe, "%s", sor);
        for (int j = 0; sor[j] != '\0'; j++)
        {
            char fscan;
            fscanf(fBe, "%c", &fscan);

            if (fscan == ',')
            {
                continue;
            }
            else if (fscan == '-')
            {
                vege = 1;
                break;
            }
            else
            {
                tomb[i] = (int)fscan;
                arrLen++;
            }
        }
        free(sor);
    }

    for (int i = 0; i < arrLen; i++)
    {
        printf("%d ", tomb[i]);
    }

    printf("\n");

    fclose(fBe);

    return 0;
}
