#include <iostream>
#include <utility>
#include <random>
#include <vector>
#include <algorithm>
using namespace std;
int Find(int lhs[],int m,int rhs[],int n,int index)
{
	int l_begin = 0,r_begin = 0;
	int l_end = m - 1,r_end = n - 1;
	int l_mid = (l_begin + l_end)/2;
	int r_mid = (r_begin + r_end)/2;

	while(l_begin < l_end && r_begin < r_end)
	{
		l_mid = (l_end + l_begin)/2;
		r_mid = (r_end + r_begin)/2;
		if(lhs[l_mid] > rhs[r_mid])
		{
			if(index <= l_mid - l_begin + 1 + r_mid - r_begin + 1)
			{
				cout << "1" << endl;
				r_end = r_mid;
			}
			else
			{
				cout << "2" << endl;
				l_begin = l_mid;
			}
		}
		else
		{
			if(index <= l_mid - l_begin + 1 + r_mid - r_begin + 1) 
			{
				cout << "3" << endl;
				l_end = l_mid;
			}
			else
			{
				cout << r_begin << r_end << endl;
				r_begin = r_mid;
			}
		}
	}
	if(l_begin == l_end)
		return rhs[r_begin + index - 1];
	else if(r_begin == r_end)
		return lhs[l_begin + index - 1];
	else
		return -1;
}

int main(int argc,char** argv)
{
	const int m = stoi(argv[1]);
	const int n = stoi(argv[2]);
	const int index = stoi(argv[3]);
	if(index <= 0 || index > m + n)
	{
		cout << "index out of range" << endl;
		exit(1);
	}
	int* lhs = new int[m];
	int* rhs = new int[n];
	int initl = 0;
	int initr = m;
	for(int i = m - 1;i >= 0;i--)
		lhs[i] = initl++;
	for(int i = n - 1;i >= 0;i--)
		rhs[i] = initr++;

	for(int i = 0;i < m;i++)
		cout << lhs[i] << " ";
	cout << endl;
	for(int i = 0;i < n;i++)
		cout << rhs[i] << " ";
	cout << endl;
	cout << Find(lhs,m,rhs,n,index) << endl;
	return 0;
}
