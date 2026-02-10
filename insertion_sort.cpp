#include <iostream>
void insertion_sort(int* arr, int size)
{
    for(int i = 1; i < size; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int size = 10;
    int arr[size] = {4,5,6,7,8,9,0,2,1,6};
    std::cout << "<======= Array Before Insertion Sort =======>" << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    insertion_sort(arr, size);
    std::cout << std::endl << "<======= Array After Insertion Sort =======>" << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    
}