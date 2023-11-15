#include <stdio.h>

int main() {

  int day;
  printf("Add meg a nap számát: ");
  scanf("%d", &day);

  switch (day)
  {
  case 1:
    printf("hetfo");
    break;
  case 2:
    printf("kedd");
    break;
  case 3:
    printf("szerda");
    break;
  case 4:
    printf("csutortok");
    break;
  case 5:
    printf("pentek");
    break;
  case 6:
    printf("szombat");
    break;
  case 7:
    printf("vasarnap");
    break;
  default:
    printf("Helytelen!");
    break;
  }

  printf("\n");

  return 0;
}