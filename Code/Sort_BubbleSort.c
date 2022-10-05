#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
    printf("\n");
}
// void swap(int *a, int *b)
// {
//     int *temp;
//     temp = b;
//     b = a;
//     a = temp;
// }


// The worst-case time complexity of Bubble Sort is: O(n^2)
// The best-case time complexity of Bubble Sort is: O(n)

void bubbleSortAdaptive(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For number of pass. It'll run (n-1) times.
    {
        printf("Working on pass number: %d\n", i + 1);
        isSorted = 1;                       // Assuming the array is already sorted
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                // swap(A[j],A[j+1]);
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return; // This exits the loop ( acts as break)
        }
    }
}
void bubbleSort(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // For number of pass. It'll run (n-1) times.
    {
        printf("Working on pass number: %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++) // For comparison in each pass
        {
            if (A[j] > A[j + 1])
            {
                // swap(A[j],A[j+1]);
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
int main()
{
    // int A[] = {12, 34, 18, 4, 6, 8};
    int A[] = {1, 2, 3, 4, 5, 6};
    // int A[] = {1, 2, 6, 7, 9, 54, 123, 534,6, 70, 99, 5, 6, 37, 67, 56, 29, 46};
    int n = 6;
    // int n = 18;
    printArray(A, n); // Printing array before sorting
    bubbleSort(A, n); // Function to sort the array
    printArray(A, n); // Printing array after sorting

    printf("\nThis is by using adaptive bubble sort \n");
    bubbleSortAdaptive(A, n); // Function of Bubblesort Adaptive array
    printArray(A, n);
    return 0;
}