//matrix-chain product
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
//print the solution
void Print(vector<vector<unsigned int>>& division,int i,int j)
{
	if(i == j)
		return;
	Print(division,i,division[i][j]);
	Print(division,division[i][j]+1,j);
	cout << "(" << i << "," + division[i][j] << ")" <<
		"(" << division[i][j]+1 << "," << j << ")" << endl;
}

//retrive the result
void MatrixChain(unsigned int length,unsigned int input[],
		vector<vector<unsigned int>>& result,
		vector<vector<unsigned int>>& division)
{
	//the number of matrix
	unsigned int num = length - 1;
	result.clear();
	//initialize vector
	for(int i = 0;i < num;i++)
		result.emplace_back(num);
	division.clear();
	for(int i = 0;i < num;i++)
		division.emplace_back(num);
	//single matrix caculation cost is 0
	for(int i = 0;i < num;i++)
		result[i][i] = 0;
	
	//d presents the distance
	for(int d = 1;d < num;d++)
	{
		for(int i = 0;i < num - d;i++)
		{
			//j presents the right side of the region
			int j = i + d;
			//result value of initial division where k = i
			//result[i][i] = 0 no need to be caculated
			result[i][j] = result[i+1][j] + input[i]*input[i+1]*input[j+1];
			//record division k = i
			division[i][j] = i;
			//find the best position of k (division)
			for(int k = i + 1;k < j;k++)
			{
				int tmp = result[i][k] + result[k+1][j] + 
					input[i]*input[k+1]*input[j+1];
				if(tmp < result[i][j])
				{
					result[i][j] = tmp;
					division[i][j] = k;
				}
			}
		}
	}
}


int main()
{
	unsigned int* input = nullptr;
	//the number of instances
	int arrayNum;
	cin >> arrayNum;
	//input
	while(arrayNum--)
	{
		//for each instance the number of mumbers
		int mumberNum;
		cin >> mumberNum;
		int tmp = mumberNum;
		input = new unsigned int[mumberNum];
		//for each mumber get its value
		int i = 0;
		while(mumberNum--)
			cin >> input[i++];
		//new result and division vector
		vector<vector<unsigned int>> res;
		vector<vector<unsigned int>> divi;
		//call the retrive function
		MatrixChain(tmp,input,res,divi);
		Print(divi,0,tmp - 2);
		delete[] input;
		input = nullptr;
	}
}