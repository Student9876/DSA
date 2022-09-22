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

int partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++; // If pivot is less than the A[i] then we are increasing the i value to find the value larger than pivot
        }
        while (A[j] > pivot)
        {
            j--; // If pivot is greater than the A[j] then we are decreasing the j value to find the value smaller than pivot
        }
        if (i < j)
        {
            // swapping values when a match is found
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // swapping the pivot
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j; // returning the value of j from where the partition starts in two sides
}
void quickSort(int *A, int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // Sort left subarray
        quickSort(A, partitionIndex + 1, high); // Sort right subarray
    }
}
int main()
{
    int A[] = {3, 1, 2, 9, 12, 7, 8, 2, 45};
    int n = 8;
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}