#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//number of queens
const unsigned int n = 8;
//store total solusion
//vector<vector<int>> totalSolution;
//total number of solutions
unsigned int sum = 0;

//judge whether the row number is valid
bool Isvalid(int row,const vector<int>& curr)
{
	//for each column
	for(int c = 1;c < row;c++)
	{
		if(abs(row - c) == abs(curr[row] - curr[c])
			|| curr[row] == curr[c])
			return false;
		else
			return true;
	}
}

void Backtrace(int row,vector<int>& curr)
{
	if(row > n)
	{
		sum++;
		//totalSolution.push_back(currSolution);
	}
	else
	{
		//for each child node
		for(int i = 1;i <= n;i++)
		{
			curr[row] = i;
			if(Isvalid(row,curr))
				Backtrace(row+1,curr);
		}
	}
}

int main()
{
	//store current solution
	vector<int> currSolution;
	//initialize the currSolution
	for(int i = 0;i <= n;i++)
		currSolution.push_back(0);
	Backtrace(1,currSolution);
	cout << sum << endl;
	return 0;
}