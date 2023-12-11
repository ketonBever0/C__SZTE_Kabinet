#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *fBe = fopen("./be.txt", "r");
    if (fBe == NULL)
    {
        printf("Nem olvashato be fajl!\n");
        return -1;
    }

    char *uzenet = malloc(sizeof(char) * 512);

    // char uzenet[512];

    fscanf(fBe, "%s", uzenet);

    int hossz = 0;

    for (int i = 0; uzenet[i] != '\0'; i++)
    {
        hossz++;
    }

    char abc[36] = "abcdefghijklmnopqrstuvwxyz0123456789";
    int szamlalo = 0;

    char **tabla = malloc(sizeof(char *) * 6);
    for (int i = 0; i < 6; i++)
    {
        tabla[i] = malloc(sizeof(char) * 6);
        for (int j = 0; j < 6; j++)
        {
            tabla[i][j] = abc[szamlalo];
            // printf("%3c", tabla[i][j]);
            szamlalo++;
        }
        // printf("\n");
    }

    szamlalo = 0;
    int uzenetSzamlalo = 0;

    FILE *fKi = fopen("./ki.txt", "w");

    int vanHiba = 0;

    for (; uzenetSzamlalo < hossz; uzenetSzamlalo++)
    {
        for (int szamlalo = 0; szamlalo < 36; szamlalo++)
        {
            if (abc[szamlalo] == uzenet[uzenetSzamlalo])
            {
                break;
            }

            if (szamlalo == 35)
            {
                fprintf(fKi, "HIBA:%d:%c\n", uzenetSzamlalo, uzenet[uzenetSzamlalo]);
                vanHiba = 1;
            }
        }
    }

    if (vanHiba == 1)
    {
        return 0;
    }

    fprintf(fKi, "%d\n", hossz);

    for (uzenetSzamlalo = 0; uzenetSzamlalo < hossz; uzenetSzamlalo++)
    {
        for (szamlalo = 0; szamlalo < 36; szamlalo++)
        {
            if (uzenet[uzenetSzamlalo] == abc[szamlalo])
            {
                for (int i = 0; i < 6; i++)
                {
                    for (int j = 0; j < 6; j++)
                    {
                        if (tabla[i][j] == abc[szamlalo])
                        {
                            fprintf(fKi, "%d%d\n", i + 1, j + 1);
                        }
                    }
                }
            }
        }
    }

    free(uzenet);
    for (int i = 0; i < 6; i++)
    {
        free(tabla[i]);
    }
    free(tabla);

    fclose(fKi);

    return 0;
}