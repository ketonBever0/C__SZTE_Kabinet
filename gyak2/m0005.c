#include <stdio.h>

int main()
{
    float pi = 3.14;
    char sideLetter = 'A';
    int sideA, sideB;

    sideA = 12;
    sideB = 4;

    printf("Pi: %f\n", pi);
    printf("Karakter: %c\n", sideLetter);
    printf("A oldal: %d\n", sideA);
    printf("B oldal: %d\n", sideB);

    printf("\nOldalak összege: %d\n", sideA + sideB);
    printf("Oldalak szorzata: %d\n", sideA * sideB);

    return 0;
}
