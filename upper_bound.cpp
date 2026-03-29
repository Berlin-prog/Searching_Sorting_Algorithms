#include <iostream>

int upper_bound(int* arr, int target, int size)
{
    int start = 0;
    int end = size;
    while(start < end)
    {
        int mid = start + (end - start) / 2;
        if(arr[mid] <= target) start = mid + 1;
        else end = mid;
    }
    return start;
}

int main()
{
    const int SIZE = 3;
    int arr[SIZE] = {1,2,3};
    int target = 3;
    std::cout << "first position of target is: " << upper_bound(arr, target, SIZE) << std::endl;
    return 0;
}