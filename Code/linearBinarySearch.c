#include <stdio.h>

// Code for Linear search
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}

// Code for Binary search
int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;

    low = 0;
    high = size -1;
    // Searching Starts
    while (low <= high)
    {
        mid = (low + high) / 2; // It makes a greatest
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1; // We already know that the element is not present at mid
        }
        else
        {
            high = mid - 1;
        }
    }
    // Searching Ends

    return -1; // It means something from the loop hasn't returned
}

int main()
{
    // Unsorted array for Linear Search
    int arr1[] = {1, 4, 6, 23, 64, 2, 75234, 67, 32, 78};
    int size1 = sizeof(arr1) / sizeof(int); // this calculates the size of an array
    int element1 = 23;
    int searchIndex = linearSearch(arr1, size1, element1);
    printf("\n\nThe element %d is found in Index %d \n\n", element1, searchIndex);

    // Sorted array for Binary Search
    int arr2[] = {1, 4, 6, 23, 32, 64, 250, 578};
    int size2 = sizeof(arr2) / sizeof(int); // this calculates the size of an array
    int element2 = 250;
    searchIndex = binarySearch(arr2, size2, element2);
    printf("The element %d is found in Index %d \n", element2, searchIndex);
    return 0;
}