#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
//xiantao
//i...m m+1...n
void Merge(int origin[],int result[],int i,int m,int n)
{
	int q = i;
    //用于结果数组索引
    int k = i;
    //用于第二个数组索引
    int j = m + 1;
    //开始合并
    while(i <= m && j <= n)
    {
        if(origin[i] > origin[j])
            result[k++] = origin[j++];
        else
            result[k++] = origin[i++];
    }
    while(i <= m)
        result[k++] = origin[i++];
    while(j <= n)
        result[k++] = origin[j++];
    //复制
    for(;q <= n;q++)
    {
    	origin[q] = result[q];
    }
}

void Sort(int origin[],int result[],int begin,int end)
{
	if(begin < end)
	{
		int mid = (begin + end)/2;
		Sort(origin,result,begin,mid);
		Sort(origin,result,mid+1,end);
		Merge(origin,result,begin,mid,end);
	}
}

void MergeSort(int array[],int n)
{
	int* temp = new int[n];
	if(temp == nullptr)
		exit(1);
	Sort(array,temp,0,n - 1);
    delete[] temp;
}


//二分查找
bool BinarySearch(int array[],int n,int key)
{
	int left = 0,right = n - 1,mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(array[mid] == key)
			return true;
		else if(key < array[mid])
			right = mid - 1;
		else 
			left = mid + 1;
	}
	return false;
}

int main(int argc,char** argv)
{
	const int length = 10;
	int key = std::stoi(argv[1]);
	int* numberList = new int[length];
	std::default_random_engine engine;
    std::uniform_int_distribution<int> u(1,10);

    for(int i = 0;i < length;i++)
    	numberList[i] = u(engine);
    MergeSort(numberList,length);
   	for(int t = 0;t < length;t++)
   		if(BinarySearch(numberList,length,key - numberList[t]))
   		{
   			std::cout << "Yes" << std::endl;
    		return 0;
    	}
    std::cout << "No" << std::endl;
    return 0;
}