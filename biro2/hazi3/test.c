#include <stdio.h>

#define MAX_ARR_SIZE 100

int atlag(int bemenet[], int magassag)
{

    int arrLen = 0;

    while (bemenet[arrLen] != 0)
    {
        arrLen++;
    }

    int tooHigh = 0;

    int newArr[MAX_ARR_SIZE] = {};


    int i = 0;
    int j = 0;
    while (i < arrLen)
    {
        if (bemenet[i] > magassag)
        {
            tooHigh++;
            newArr[j] = bemenet[i];
            j++;
            
        }
        i++;
    }

    arrLen = 0;
    while (newArr[arrLen] != 0)
    {
        arrLen++;
    }

    // printf("%d\n", arrLen);

    if(arrLen == 0) return 0;

    int sum = 0;
    for (int i = 0; i < arrLen; i++)
    {
        // printf("%d ", newArr[i]);
        sum += newArr[i];
    }
    int avg = sum / arrLen;

    return avg;
}

int main()
{

    int arr[] = {12, 32, 16, 40, 21, 0};

    // printf("Atlag vizmagassag: ");
    printf("%d\n", atlag(arr, 21));
    return 0;
}