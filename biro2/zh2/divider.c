#include <stdio.h>


int divider (int a, int b) {

    int val = 1;

    int i;
    for (i = 1; a + b + 1 >= i; ++i) {
        if (a % i == 0 && b % i == 0) val = i;
    }

    return val;
}



int main () {

    printf("%d", divider(4, 7));

    return 0;
}