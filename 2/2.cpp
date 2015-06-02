//Longest Common Subsequence
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using IntVec = vector<vector<int>>;

//retrive the length of lcs
int LcsLength(const string& lhs,const string& rhs,
	IntVec& trace)
{
	trace.clear();
	int llen = lhs.length();
	int rlen = rhs.length();
	//new IntVec presents the result array
	IntVec result;
	//initialize 0
	for(int i = 0;i <= llen;i++)
	{
		result.emplace_back(rlen+1);
		trace.emplace_back(rlen+1);
	}
	//begin retrive
	for(int i = 0;i < llen;i++)
	{	
		for(int j = 0;j < rlen;j++)
		{
			//if condition 1
			if(lhs[i] == rhs[j])
			{
				result[i+1][j+1] = result[i][j] + 1;
				//indicate this is condition 1
				trace[i+1][j+1] = 1;
			}
			//if condition 2
			else if(result[i][j+1] >= result[i+1][j])
			{
				result[i+1][j+1] = result[i][j+1];
				trace[i+1][j+1] = 2;
			}
			else
			{
				result[i+1][j+1] = result[i+1][j];
				trace[i+1][j+1] = 3;
			}
		}
	}
	return result[llen][rlen];
}

void Lcs(int i,int j,const string& lhs,const IntVec& trace)
{
	if(i == 0 || j == 0)
		return;
	if(trace[i+1][j+1] == 1)
	{
		Lcs(i-1,j-1,lhs,trace);
		cout << lhs[i];
	}
	else if(trace[i+1][j+1] == 2)
		Lcs(i-1,j,lhs,trace);
	else 
		Lcs(i,j-1,lhs,trace);
}

int main()
{
	int groupNum;
	cin >> groupNum;
	while(groupNum--)
	{
		string lhs;
		string rhs;
		cin >> lhs >> rhs;
		IntVec trace;
		cout << LcsLength(lhs,rhs,trace) << endl;
		Lcs(lhs.length()-1,rhs.length()-1,lhs,trace);
	}
	return 0;
}