#include <stdio.h>

#define STR_LEN 1000

int strLen(char str[])
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

char reversed[STR_LEN], cutted[STR_LEN];

void reverse(char str[])
{

    int len = 0, end = 0;

    len = strLen(str);

    end = len - 1;

    for (int i = 0; i < len; i++)
    {
        reversed[i] = str[end];
        end--;
    }

    // printf("%s\n", result);
}

void cut(char str[], int from, int to)
{

    // int len = strLen(str);

    for (int i = from; i < to; i++)
    {
        cutted[i] = str[i];
    }

    printf("%s\n", cutted);
}


void titkosit(char bemenet[], char kimenet[])
{

    char reversed[STR_LEN], lengths[STR_LEN], fragmented[STR_LEN];

    int start = 0, end = strLen(bemenet);

    // cut("hello", 0, 5);

    int i = 0, k = 0;
    while (bemenet[i] != '\0')
    {
        for (int j = 0; j < end; j++)
        {
            if (bemenet[j] == ' ')
            {
                cut(bemenet, k, j - 1);
                reverse(cutted);
                fragmented[k] = reversed;
                printf("%s\n", fragmented);
                k++;
            }
        }
    }
}

int main()
{

    char str[STR_LEN] = "hello";

    char cutting[STR_LEN] = str[3] - str[2];

    printf("%s", cutting);

    return 0;
}