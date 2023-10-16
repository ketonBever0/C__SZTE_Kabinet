#include <stdio.h>


// INFO: ennél struct-al kell definiálni példányt

// struct TriangleType
// {
//     int a;
//     int b;
//     int c;
// }

typedef struct {
    int a, b, c;
} TriangleType;

TriangleType readline()
{
    int a, b, c;

    TriangleType triangle = {.a = 0, .b = 0, .c = 0};

    printf("Kérem a háromszög oldalait: ");
    scanf("%d %d %d", &triangle.a, &triangle.b, &triangle.c);

    return triangle;
}

void printline(TriangleType t)
{
    printf("Haromszog: a = %d, b = %d, c = %d\n", t.a, t.b, t.c);
}

int kerulet(TriangleType h)
{
    return h.a + h.b + h.c;
}

int main()
{
    TriangleType x = readline();

    int ker = kerulet(x);

    printf("Kerulet: %d\n");

    return 0;
}