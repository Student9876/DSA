#include <stdio.h>
#include <stdlib.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    int indexOfMin;
    int temp;
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
        // swap A[i] & A[indexOfMin]
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}
int main()
{
    // There will be total n-1 passes
    // Input array
    // 0   1   2   3    4   5
    // 03, 01, 09, 12, 07, 08

    int A[] = {3, 1, 9, 12, 7, 8};
    int n = 6;
    printArray(A, n);
    selectionSort(A, n);
    printArray(A, n);

    return 0;
}