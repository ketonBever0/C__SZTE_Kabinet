#include <stdio.h>

int main() {

  // int num = 0;

  // while(num <= 10) {
  //   printf("%d\n", num);
  //   num++;
  // }


  int inputNum;
  scanf("%d", &inputNum);

  do {
    scanf("%d", &inputNum);
  } while (inputNum != 0);


  return 0;

}