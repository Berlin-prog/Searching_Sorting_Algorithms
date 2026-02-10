#include <iostream>
void merge(int* arr, int left, int middle, int right)
{
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    for(int i = 0; i < leftSize; ++i)
    {
        leftArr[i] = arr[left + i];
    }
    for(int i = 0; i < rightSize; ++i)
    {
        rightArr[i] = arr[middle + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while(i < leftSize && j < rightSize)
    {
        if(rightArr[j] < leftArr[i])
        {
            arr[k] = rightArr[j];
            ++j;
        } else 
        {
            arr[k] = leftArr[i];
            ++i;
        }
        ++k;
    }

    while(i < leftSize)
    {
        arr[k] = leftArr[i];
        ++k;
        ++i;
    }

    while(j < rightSize)
    {
        arr[k] = rightArr[j];
        ++k;
        ++j;
    }
    delete[] leftArr;
    delete[] rightArr;
}

void merge_sort(int* arr, int left, int right)
{
    if(left < right)
    {
        int middle = left + (right - left) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int main()
{
    int size = 10;
    int arr[size] = {4,5,6,7,8,9,0,2,1,6};
    std::cout << "<======= Array Before Merge Sort =======>" << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    merge_sort(arr, 0, size - 1);
    std::cout << std::endl << "<======= Array After Merge Sort =======>" << std::endl;
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
}