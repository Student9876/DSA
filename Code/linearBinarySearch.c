#include <stdio.h>


int linearSearch(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element)
            return i;
    }
    return -1;
    
}
int main()
{
    int arr[]={1,4,6,23,64,2,75234,67,32,78};
    int size = sizeof(arr)/sizeof(int); //this calculates the size of an array
    int element = 64;
    int searchIndex= linearSearch(arr,size,element);
    printf("The element %d is found in Index %d",element, searchIndex);
    return 0;
}