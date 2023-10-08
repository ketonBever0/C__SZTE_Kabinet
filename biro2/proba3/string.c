#include <stdio.h>

int length (char str[]) {
    
    int i;

    for (i = 0; str[i] != '\n'; ++i);

    return i;
}

int main () {

    char str[] = "hello";

    // printf("%d\n", length(str));
    printf("%c\n", str[]);

    return 0;
}