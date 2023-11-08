/*
 * Szegedi Tudományegyetem
 * Informatikai Tanszékcsoport
 * Szoftverfejlesztés Tanszék
 *
 * Programozás Alapjai
 */

#include <stdio.h>

int main() {
    int a = 10;
    int *pa;


    pa = &a;


    printf(" a=%18d   pa=%#18llx\n", a, (long long int)pa);
    printf("&a=%#18llx  &pa=%#18llx\n", (long long int)&a, (long long int)&pa);
    printf("                       *pa=%18d\n", *pa);

    return 0;
}
