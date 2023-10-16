#include <stdio.h>

int concat(int arr1[], int result[], int arr2[], int len1, int len2)
{

  for (int i = 0; i < len1; i++)
  {
    result[i] = arr1[i];
  }

  int j = 0;
  for (int i = len1; i < len1 + len2; i++)
  {
    result[i] = arr2[j];
    printf("%d\n", result[j]);
    j++;
  }
  

  return len1 + len2;


}

int main()
{

  int arr1[] = {1, 2, 3};
  int result[] = {};
  int arr2[] = {4, 5, 6};

  printf("%d\n", concat(arr1, result, arr2, 3, 4));

  return 0;
}