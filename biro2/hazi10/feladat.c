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

    int meret = 20;

    fclose(fBe);

    return 0;
}
