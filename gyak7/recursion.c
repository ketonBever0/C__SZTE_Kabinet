#include <stdio.h>


int fact(int number) {

    /* printf("%d\n", number); */

    int f = 0;

    if(number == 0 || number < 0 ) return 1;
    else f = number * fact(number - 1);
    return f;

}


int main() {

    int num;

    scanf("%d", &num);

    printf("%d! = %d\n", num, fact(num));

    return 0;
}