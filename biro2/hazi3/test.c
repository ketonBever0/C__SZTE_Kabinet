#include <stdio.h>

int atlag(int bemenet[], int magassag)
{

    int arrLen = 0;

    while (bemenet[arrLen] != 0)
    {
        arrLen++;
    }

    int tooHigh = 0;

    int newArr[] = {};

    int helper = 0;

    int i = 0;
    while (i < arrLen)
    {
        if (bemenet[i] > magassag)
        {
            // helper = bemenet[i];
            // newArr[i] = helper;
            newArr[i] = bemenet[i];
            tooHigh++;
        }
        i++;
    }

    arrLen = 0;
    while (newArr[arrLen] != 0)
    {
        arrLen++;
    }

    printf("%d\n", arrLen);

    printf("eljut");

    // for (int i = 0; i < arrLen; i++)
    // {
    //     printf("%d ", newArr[i]);
    // }

    return arrLen;
}

int main()
{

    int arr[] = {3, 5, 20, 50, 60, 0};

    // printf("Atlag vizmagassag: ");
    printf("%d\n", atlag(arr, 30));

    return 0;
}