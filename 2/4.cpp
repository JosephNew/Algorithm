#include <iostream>
#include <tuple>
#include <climits>
#include <string>

using namespace std;

//cross-low cross-high cross-sum
using Res = tuple<unsigned int ,unsigned int,int>;

//low...mid mid+1...high
Res GetMaxCrossSubarray(int* arr,unsigned int low,unsigned int mid,unsigned int high)
{
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int max_left = low;
	int max_right = high;
	//temporary sum 
	int sum = 0;
	for(int i = mid;i >= low;i--)
	{
		//cout << "low=" << low << endl;
		cout << i << endl;
		sum += arr[i];
		//cout << "end" << endl;
		if(sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	//cout << "sub mid = " << mid << "sub high=" << high << endl;
	sum = 0;
	for(int i = mid + 1;i <= high;i++)
	{
		sum += arr[i];
		if(sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}

	return make_tuple(max_left,max_right,left_sum + right_sum);
}

Res GetMaxSubarray(int* arr,unsigned int low,unsigned int high)
{
	if(low == high)
		return make_tuple(low,high,arr[low]);
	unsigned int mid = (low + high)/2;
	//cout << "mid=" << mid << " low=" << low <<  " high = " << high << endl;
	Res left = GetMaxSubarray(arr,low,mid);
	Res right = GetMaxSubarray(arr,mid + 1,high);
	Res cross = GetMaxCrossSubarray(arr,low,mid,high);

	auto left_sum = get<2>(left);
	auto right_sum = get<2>(right);
	auto cross_sum = get<2>(cross);

	if(left_sum >= right_sum && left_sum >= cross_sum)
		return left;
	else if(right_sum >= left_sum && right_sum >= cross_sum)
		return right;
	else
		return cross;
}

int main()
{
	int length;
	cin >> length;
	int* arr = new int[length];
	for(int i = 0;i < length;i++)
		cin >> arr[i];
	cout << "???" << endl;
	//cout << "fuck" << endl;
	auto res = GetMaxSubarray(arr,0,length - 1);
	cout << "left : " << get<0>(res) << " right :"
	<< get<1>(res) << " sum : " << get<2>(res) << endl;
	return 0;
}