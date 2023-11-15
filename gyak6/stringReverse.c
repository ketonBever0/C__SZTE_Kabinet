#include <stdio.h>

void reverse(char str[])
{

    int len = 0;

    while (str[len] != '\n')
    {
        len++;
    }

    printf("%c\n", str);
    printf("%d\n", len);


}

int main() {

    reverse("as");

    return 0;
}