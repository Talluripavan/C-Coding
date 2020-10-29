#include<stdio.h>
#include<stdlib.h>
void
SWAP (int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int
partition (int arr[], int l, int n)
{
  int piv = arr[n];
  int i = l - 1;

  for (int j = 0; j < n; j++)
    {
      if (arr[j] < piv)
	{
	  i++;
	  SWAP (&arr[i], &arr[j]);
	}
    }
  SWAP (&arr[i + 1], &arr[piv]);
  return i + 1;
}

void
Quicksort (int arr[], int l, int n)
{
  if (l < n)
    {
      int mid = partition (arr, l, n);

      Quicksort (arr, l, mid-1);
      Quicksort (arr, mid + 1, n);
    }
  return;
}

void
printArray (int arr[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf ("%d ", arr[i]);
  printf ("n");
}


int
main ()
{
  int arr[] = { 10, 7, 8, 9, 1, 5 };
  int n = sizeof (arr) / sizeof (arr[0]);
  Quicksort (arr, 0, n - 1);
  printf ("Sorted array: n");
  printArray (arr, n);

  return 0;
}
