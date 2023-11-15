#include <stdio.h>

int harcIdo(int eletero, int sebzes) {

    int korok = 0;
    if(sebzes <= 0) return -1;
    if(eletero <= 0) return 0;
    while(eletero > 0) {
        korok++;
        eletero -= sebzes;
    }

    return korok;
}


int main() {
    printf("%d\n", harcIdo(17, 5));
    return 0;
}