//scheduling problem
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main()
{
	int num;
	cin >> num;
	vector<pair<int,int>> times;
	int i = 0;
	while(num--)
	{
		int tmp;
		cin >> tmp;
		times.push_back(pair<int,int>(tmp,i++));
	}
	sort(times.begin(),times.end(),
		[](const pair<int,int>& l,const pair<int,int>& r){
			return l.first < r.first;});
	for(auto& val : times)
		cout << val.second << " ";
	return 0;
}