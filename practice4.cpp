#include <iostream>
#include <utility>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;

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

int Find(int lhs[],int m,int rhs[],int n,int index)
{
	int l_begin = 0,r_begin = 0;
	int l_end = m,r_end = n;
	int l_mid = (l_begin + l_end)/2;
	int r_mid = (r_begin + r_end)/2;

	while(l_begin < l_end && r_begin < r_end)
	{
		l_mid = (l_end + l_begin)/2;
		r_mid = (r_end + r_begin)/2;
		if(lhs[l_mid] > rhs[r_mid])
		{
			if(index < l_mid + r_mid)
				r_end = r_mid;
			else
				l_begin = l_mid;
		}
		else
		{
			if(index < l_mid + r_mid)
				l_end = l_mid;
			else
				r_begin = r_mid;
		}
	}
	if(l_begin == l_end)
		return rhs[r_begin + index];
	else if(r_begin == r_end)
		return lhs[l_begin + index];
	else
		return -1;
}

int main(int argc,char** argv)
{
	const int m = stoi(argv[1]);
	const int n = stoi(argv[2]);
	const int index = stoi(argv[3]);
	default_random_engine engine1(32767);
	default_random_engine engine2(65535);
	uniform_int_distribution<unsigned> u(1,1000);
	
	int* lhs = new int[m];
	int* rhs = new int[n];

	for(int i = 0;i < m;i++)
	{
		lhs[i] = u(engine1);
		cout << lhs[i] << endl;
	}
	for(int i = 0;i < n;i++)
	{
		rhs[i] = u(engine2);
		cout << rhs[i] << endl;
	}
	QuickSort(lhs,0,m - 1);
	QuickSort(rhs,0,n - 1);
	cout << Find(lhs,m,rhs,n,index) << endl;
	return 0;
}
