#include <iostream>

void QuickSort(int arr[],int begin,int end)
{
	if(begin > end)
        return;
    //设置轴元素值
    int pivot = arr[begin];
    //设置两方向计数
    int left = begin;
    int right = end;
    //扫描一遍数组，将轴元素放至正确位置
    while(left < right)
    {
        //先将right向左移动，找到第一个比轴元素小的元素
        while(left < right && arr[right] >= pivot)
            --right;
        //如果找到则直接将该元素赋值给arr[low]因为arr[low]值被pivot存储
        if(left < right)
            arr[left] = arr[right];
        //再将low向上移动，找到第一个比轴元素大的元素
        while(left < right && arr[left] <= pivot)
            ++left;
        //赋值
        if(left < right)
            arr[right] = arr[left];
    }
    //给轴元素赋值
    arr[left] = pivot;
    //此时left和right已经相等
    //递归左右两部分
    QuickSort(arr,begin,left - 1);
    QuickSort(arr,right + 1,end);
}