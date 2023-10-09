#include <stdio.h>

int charlen (char c) {
    if ('A' <= c && 'Z' >= c) return 2;
    else if ('0' <= c && c >= '9') return 1;
    else return 0;
}

int main () {

    printf("%d", charlen('W'));

    return 0;
}