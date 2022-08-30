#include <stdio.h>

// Code for traversal
void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);  
    }
    printf("\n");
}

// Code for Insertion
int indInsertion(int arr[], int size, int element, int capacity, int index ){
    if(size>= capacity)
        return -1;
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[100] = {1, 2, 3, 5, 7, 34};
    int val, size = 6, index = 3, element = 45; 
    display(arr,size);

    val = indInsertion(arr, size, element, 100, index );
    if(val==-1)
        printf("Insertion Failed");
    printf("Insertion Done\n");
    
    size+=1;
    display(arr,size);

    return 0;
}