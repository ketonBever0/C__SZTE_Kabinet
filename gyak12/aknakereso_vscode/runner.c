#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Hibas parameterek!");
        return 0;
    }

    int res = system("gcc main.c -o aknakereso");

    if (res == 0) {
        char str[100];
        sprintf(str, "java -jar game.jar -name Aknakereso -code %s -gui %s", argv[1], argv[2]);
        system(str);
    }

    return 0;
}