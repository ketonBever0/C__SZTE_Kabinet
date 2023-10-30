#include <stdio.h>

typedef struct LEGO_lap
{
    int a_oldal;
    int b_oldal;
} LEGO_lap;

int terulet(LEGO_lap lap)
{
    return lap.a_oldal * lap.b_oldal;
}

void rendez(LEGO_lap LEGO_lapok[], int n)
{

    printf("NEM rendezett:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", terulet(LEGO_lapok[i]));
    }

    int legkisebb_index;
    LEGO_lap csere;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            legkisebb_index = i;
            if (terulet(LEGO_lapok[j]) > terulet(LEGO_lapok[i]))
            {
                legkisebb_index = j;
                csere = LEGO_lapok[legkisebb_index];
                LEGO_lapok[legkisebb_index] = LEGO_lapok[i];
                LEGO_lapok[i] = csere;
            }
        }
    }

    printf("Rendezett:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", terulet(LEGO_lapok[i]));
    }
}

int main()
{

    LEGO_lap lapok[] = {
        {.a_oldal = 40,
         .b_oldal = 50},
        {.a_oldal = 16,
         .b_oldal = 20},
        {.a_oldal = 3,
         .b_oldal = 6},
        {.a_oldal = 96,
         .b_oldal = 51},
    };

    rendez(lapok, 4);

    return 0;
}