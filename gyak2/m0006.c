#include <stdio.h>

int main()
{
    int sideA, sideB, replaceHelper;

    printf("Írj egy egész értéket az A oldalnak: ");
    scanf("%d", &sideA);

    printf("Írj egy egész értéket a B oldalnak: ");
    scanf("%d", &sideB);

    replaceHelper = sideB;
    sideB = sideA;
    sideA = replaceHelper;

    printf("\nA: %d\n", sideA);
    printf("B: %d\n", sideB);

    return 0;
}
