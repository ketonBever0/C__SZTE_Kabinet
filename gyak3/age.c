#include <stdio.h>

int main() {
  
  int curYear = 2023;
  int curMonth = 9;
  int curDay = 18;
  int bornYear;
  int bornMonth;
  int bornDay;

  printf("Írd be a születési éved: ");
  scanf("%d", &bornYear);

  printf("Írd be a születési hónapod számát: ");
  scanf("%d", &bornMonth);

  printf("Írd be a születési napodat: ");
  scanf("%d", &bornDay);

  int age = curYear - bornYear;

  
  if (bornYear == curYear && bornMonth == curMonth && bornDay == curDay) {
    printf("Ma születtél!");
  }
  else if (bornYear == curYear && bornMonth == curMonth) {
    if (bornDay <= curDay) {
      printf();
    }
  }


  // printf("%d\n", age);

  return 0;

}
