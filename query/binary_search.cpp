#include <stdio.h>
#include <stdlib.h>

// 递归
int BinarySearch(int Arr[], int left, int right, int key)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (Arr[mid] == key)
        {
            return mid;
        }
        else if (Arr[mid] < key)
        {
            left = mid + 1;
            return BinarySearch(Arr, left, right, key);
        }
        else
        {
            right = mid - 1;
            return BinarySearch(Arr, left, right,key);
        }
    }
    else
    {
        return -1;
    }
    
}

// 循环
int BinarySearch2(int Arr[], int left, int right, int key)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (Arr[mid] == key)
        {
            return mid;
        }
        else if (Arr[mid] < key)
        {
            left = mid + 1;
        }
        else 
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 10, 11};
    int b;
    b = BinarySearch2(arr, 0, sizeof(arr) / sizeof(arr[0]), 7);

    printf("%d\n", b);

    return 0;
}