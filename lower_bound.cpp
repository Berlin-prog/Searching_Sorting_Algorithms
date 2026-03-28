#include <iostream>

int lower_bound(int* arr, int target, int size)
{
    int start = 0;
    int end = size - 1;
    while(start < end)
    {
        int mid = start + (end - start) / 2;
        if(arr[mid] < target) start = mid + 1;
        else end = mid;
    }
    return start;
}

int main()
{
    const int SIZE = 10;
    int arr[SIZE] = {1,2,3,4,4,4,4,4,4,5};
    int target = 4;
    std::cout << "first position of target is: " << lower_bound(arr, target, SIZE) << std::endl;
    return 0;
}