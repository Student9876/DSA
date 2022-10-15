// Binary search works with only a sorted list 
// Binary search returns an index of the element if it exists in the List
// Average case complexity of binary search is O(log(n))
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int element, int n)
{
    int low, mid, high;
    low = 0;    
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        int item = arr[mid];
        if (item == element)
        {
            return mid;
        }
        else if (item <= element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // sort(arr,arr+n);
    int element;
    cin >> element;
    int index = binarySearch(arr, element, n);
    cout << index;
    return 0;
}