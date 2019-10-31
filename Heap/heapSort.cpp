#include <vector>
#include <iostream>

using namespace std;

// 将num[i]进行下沉操作，此时堆的边界为n
void SinkDown(vector<int> &nums, int n, int i)
{
    int j;
    while (true)
    {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        j = i; // j为下一个该下沉的节点
        if (leftChild < n && nums[leftChild] > nums[j])
        {
            j = leftChild;
        }

        if (rightChild < n && nums[rightChild] > nums[j])
        {
            j = rightChild;
        }

        if (j == i) break;

        swap(nums[i], nums[j]);
        i = j;
    }
}

void BuildHeap(vector<int> &nums)
{
    int n = nums.size();
    int lastInternal = (n - 2) >> 1; // 节点i的父节点为(i-1)>>1,最后一个内节点即为末节点
    for (int i = lastInternal; i >= 0; i--)
    {
        SinkDown(nums, nums.size(), i); // 对每一个节点进行下沉
    }
}

void HeapSort(vector<int> &nums)
{
    BuildHeap(nums); // 初始建堆

    int len = nums.size();
    while (len > 1)
    {
        swap(nums[0], nums[len - 1]);
        SinkDown(nums, --len, 0);
    }
}

int main()
{
    vector<int> nums{16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    HeapSort(nums);

    for (auto i:nums)
    {
        cout << i << " ";
    }

    return 0;
}