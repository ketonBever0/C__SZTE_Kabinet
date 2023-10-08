#include <stdio.h>


int contains (char array[], char element) {
    int arrLen = 8;

    for (int i = 0; i < arrLen; i++)
    {
        if (array[i] == element) return 1;
    }

    return 0;
}

int huszar (char oszlop, char sor) {

    char col[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    char row[] = {'1', '2', '3', '4', '5', '6', '7', '8'};

    int canHit = 0;

    for (int c = 0; c < 8; c++) {
        for (int r = 0; r < 8; r++) {
            if (oszlop == col[c] && sor == row[r]) {
                // left downwards
                if (contains(col, oszlop - 1) && contains(row, sor - 2)) canHit++;
                if (contains(col, oszlop - 2) && contains(row, sor - 1)) canHit++;
                // left upwards
                if (contains(col, oszlop - 2) && contains(row, sor + 1)) canHit++;
                if (contains(col, oszlop - 1) && contains(row, sor + 2)) canHit++;
                // right downwards
                if (contains(col, oszlop + 1) && contains(row, sor - 2)) canHit++;
                if (contains(col, oszlop + 2) && contains(row, sor - 1)) canHit++;
                // right upwards
                if (contains(col, oszlop + 2) && contains(row, sor + 1)) canHit++;
                if (contains(col, oszlop + 1) && contains(row, sor + 2)) canHit++;
            }
        }
    }

    return canHit;

}

int main () {

    char testArr[] = {'a', 'b'};

    // if (contains(testArr, 'c')) printf("ASD");

    printf("%d\n", huszar('b', '6'));

    return 0;
}