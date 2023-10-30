#include <stdio.h>

int main()
{
    FILE *in;
    in = fopen("input.txt", "r");

    if (in == NULL)
    {
        printf("Opening input.txt failed!");
        return -1;
    }

    int num;

    if (fscanf(in, "%d", &num) != 1)
    {
        printf("Number scan failed!");
        return -2;
    }

    FILE *out;
    out = fopen("output.txt", "w");

    if (out == 0)
    {
        printf("Opening output.txt failed");
        return -3;
    }

    /* out = scanf("%d", &num); */

    if (fprintf(out, "%d" num * 2) == 0)
    {
        printf("File writing failed!");
        return -4;
    }

    fclose(out);
    fclose(in);

    return 0;
}