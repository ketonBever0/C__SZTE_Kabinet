#include <stdio.h>

int main() {

    char str[1000] = "hello";

    char cut[1000] = str[3] - str[2];

    printf("%s", cut);

    return 0;
}