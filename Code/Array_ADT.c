// We are using heap memory by using malloc. So it will remain untill we free it ourself
#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;  // has the address of the first element block of the dynamically allocated memory array
};

void createArray(struct myArray *a, int tSize, int uSize)
{
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize*sizeof(int));
    a->total_size = tSize;
    a->used_size = uSize;
    // It will dynamically allocate needed size of array in heap of memory. Efficient :)
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

void setVal(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d : ", i);
        scanf("%d", &n);
        (a->ptr[i]) = n;
    }
}

void insertVal(struct myArray *a, int index){
    printf("Enter index ");
    
}
int main()
{
    struct myArray marks;
    createArray(&marks, 10, 2);
    printf("We are running setVal now\n");
    setVal(&marks);

    printf("We are running Show now\n");
    show(&marks);
    return 0;
}