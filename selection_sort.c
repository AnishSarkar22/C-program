// Selection sort in C

#include <stdio.h>

void selectionSort(int *A, int n)
{
  int indexOfMin, temp;
  printf("Running Selection sort... \n");
  for (int i = 0; i < n - 1; i++)
  {
    indexOfMin = i;
    for (int j = i + 1; j < n; j++)
    {
      if (A[j] < A[indexOfMin])
      {
        indexOfMin = j;
      }
    }
    // swap A[i] and A[indexOfMin]
    temp = A[i];
    A[i] = A[indexOfMin];
    A[indexOfMin] = temp;
  }
}

void printArray(int *A, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main()
{
  int A[] = {3, 5, 2, 13, 12};
  int n = 5;
  printArray(A, n);
  selectionSort(A, n);
  printArray(A, n);

  return 0;
}