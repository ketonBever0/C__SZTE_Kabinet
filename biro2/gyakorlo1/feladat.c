#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE* fBe = fopen("./be.txt", "r");

    if (fBe == NULL) {
        printf("Nem olvashato a be.txt!");
        return -1;
    }


    int forras, cel, szam;

    if(fscanf(fBe, "%d %d %d", &forras, &cel, &szam) != 3) {
        printf("Nem olvashatoak a fajlbol az adatok!");
        return -2;
    }

    


    return 0;
}