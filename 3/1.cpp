#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using DoubleVec = vector<vector<int>>;
const unsigned int C = 10;
int FractionalChoice(vector<pair<int,int>>& input)
{
	sort(input.begin(),input.end(),
		[](const pair<int,int>& l,const pair<int,int>& r){
			return static_cast<double>(l.first)/l.second < 
			static_cast<double>(r.first)/r.second;});

	int currWeight = 0;
	int sumValue = 0;
	auto riter = input.rbegin();
	while(currWeight <= C)
	{
		currWeight += riter->second;
		sumValue += riter->first;
		++riter;
		if((currWeight+riter->second) > C)
		{
			sumValue += (C - currWeight)*
				(riter->first/riter->second);
			break;
		}
	}
	return sumValue;
}

void OneZeroChoice(vector<pair<int,int>>& input,DoubleVec& output)
{
	//total number of items
	int n = input.size();
	output.clear();
	for(int i = 0;i <= n;i++)
		output.emplace_back(C+1);
	for(int i = 0;i <= C;i++)
		output[0][i] = 0;
	for(int i = 0;i <= n;i++)
		output[i][0] = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= C;j++)
		{
			output[i][j] = output[i - 1][j];
			//if space remained
			if(j >= input[i-1].second)
				output[i][j] = max(output[i-1][j],
					output[i-1][j-input[i-1].second]+input[i-1].first);
		}
}

int main()
{
	//0 - fractional ; 1 - 0/1
	int choice;
	cin >> choice;
	if(choice == 0)
	{
		int num;
		cin >> num;
		//raw input value/weight
		vector<pair<int,int>> input;
		while(num--)
		{
			int v,w;
			cin >> v >> w;
			input.emplace_back(v,w);
		}
		cout << FractionalChoice(input) << endl;
	}
	else if(choice == 1)
	{
		int num;
		cin >> num;
		int tmp = num;
		vector<pair<int,int>> input;
		while(num--)
		{
			int v,w;
			cin >> v >> w;
			input.emplace_back(v,w);
		}
		DoubleVec out;
		OneZeroChoice(input,out);
		cout << out[tmp][C] << endl;
	}
	return 0;
}