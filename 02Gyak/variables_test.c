#include <stdio.h>

int main()
{
    int age = 23;
    float height = 188.63;
    char gender = 'M';

    printf("Kor: %d\n", age);
    printf("Magasság: %f\n", height);
    printf("Nem: %c\n", gender);

    printf("\nKor és magasság összege: %f: \n", age + height);
    printf("Karakter egész számként: %d\n", gender);

    return 0;
}
