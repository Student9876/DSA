#include <iostream>
using namespace std;

class myArray
{
public:
    int total_size;
    int used_size;
    int *ptr;
    myArray(int tSize, int uSize)
    {
        total_size = tSize;
        used_size = uSize;

        // Dynamically allocating an array of memory block and settings
        // its address of the first element block in ptr
        ptr = new int(tSize);
    }
    void setVal(void)
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << "Enter Element" << i << " :";
            cin >> ptr[i];
        }
    }
    void display(void)
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << ptr[i] << "\t";
        }
    }
};

int main()
{
    myArray marks(10, 2);
    marks.setVal();
    marks.display();

    return 0;
}