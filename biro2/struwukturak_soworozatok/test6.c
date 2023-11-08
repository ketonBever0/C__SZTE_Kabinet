#include <stdio.h>

int i = 0;
float osszkar = 0;

float karbecsles(float karok[], int darabszam) {

    if(i >= darabszam) {
        /* printf("osszkar: %f\n", osszkar); */
        float eredmeny = osszkar;
        i = 0;
        osszkar = 0;
        eredmeny;
    }

    /* printf("%f\n", karok[i]); */
    osszkar += karok[i];
    i++;
    return karbecsles(karok, darabszam);
}

int main() {

    float karok[8] = {0, 14, 27, 7, 9, 61, 0, 56};

    printf("vege: %f", karbecsles(karok, 8));



    return 0;
}