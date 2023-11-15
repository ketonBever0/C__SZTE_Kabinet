#include <stdio.h>

#define arrSize 10

void input(int arr[], int size) {
  for (int i = 0; i < arrSize; i++)
  {
    printf("Kérem a tömb %d elemét: ", i + 1);
    scanf("%d", &arr[i]);
  }
  
}

void print(int arr[]) {
  double avg;
  int sum = 0;
  for (int i = 0; i < arrSize; i++)
  {
    printf("%d. érték: %d\n", i + 1, arr[i]);
    sum += arr[i];
  }

  avg = sum / (float)arrSize;

  printf("Átlag: %lf\n", avg);
  
}

void reversePrint(int arr[]) {
  
  for (int i = arrSize; i > 0; i--)
  {
    printf("%d. érték: %d\n", i, arr[i]);
  }
}



int main() {

  int arr[arrSize];

  input(arr, arrSize);
  print(arr);

  printf("A tömb visszafele:\n");

  reversePrint(arr);


  return 0;
}
