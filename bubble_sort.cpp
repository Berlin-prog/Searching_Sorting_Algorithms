#include <iostream>
void bubble_sort(int* arr, int size)
{
    for(int i = 0; i < size - 1; ++i)
    {
        for(int j = 0; j < size - i - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "<======= Array Before Bubble Sort =======>" << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    bubble_sort(arr, size);
    std::cout << std::endl << "<======= Array After Bubble Sort =======>" << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
}