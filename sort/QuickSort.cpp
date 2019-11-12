#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[j] >= pivot && i < j)
        {
            --j;
        }

        // 如果不判断直接运算括号中的，那么++i每次执行使得 i != j，下次执行arr[j] = arr[i]会出现问题
        if (arr[j] < pivot)
        {
            arr[i] = arr[j];
            ++i;
        }

        while (arr[i] <= pivot && i < j)
        {
            ++i;
        }

        if (arr[i] > pivot)
        {
            arr[j] = arr[i];
            --j;
        }
    }

    arr[i] = pivot;

    return i;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        QuickSort(arr, low, p-1);
        QuickSort(arr, p+1, high);
    }
}

int main()
{
    int Arr[] = {1, 3, 1, 2, 5, 7, 4};
    QuickSort(Arr, 0, 6);

    for (auto &i: Arr)
    {
        printf("%d ", i);
    }

    return 0;
}