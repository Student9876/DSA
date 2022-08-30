#include <stdio.h>

// Code for traversal
void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);  
    }
    printf("\n");
}

// Code for Deletion
int indDeletion(int arr[], int size, int capacity, int index ){
    if(index>= capacity)
        return -1;
    for (int i = index; i < size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    return 1;
}

int main()
{
    int arr[100] = {1, 2, 3, 5, 7, 34};
    int val, size = 6, index = 2, element = 45; 
    display(arr,size);

    val = indDeletion(arr, size, 100, index );
    if(val==-1)
        printf("Deletion Failed");
    printf("Deletion Done\n");
    
    size-=1;
    display(arr,size);

    return 0;
}