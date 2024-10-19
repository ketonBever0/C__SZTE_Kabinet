#include <stdio.h>
/* #include <string.h> */

/* void pointer()
{
    printf("%d\n", ptr);
} */

int main(int argc, char const *argv[])
{
    int str[2];
    /* printf("%d", strlen(str)); */
    str[0] = 2;
    printf("\n");
    printf("%d", sizeof(str) / sizeof(str[0]));
    int *ptr = 50;

    return 0;
}
