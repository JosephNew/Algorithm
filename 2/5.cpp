#include <limits>
#include <iostream>

using namespace std;

void InitGraph(int n,int len,int** state, int **edge)
{
	int tmp = n;
	int i,j;
	int num = 0;

	cin >> i;
	while (i)
	{
		cin >> j;
		cin >> edge[i][j];
		cin >> i;
	}
	////
	for (i = 1;i <= len;i++)
	{
		cin >> num;
		for (j = 0;j < num;j++)
			cin >> state[i][j];
	}
}
//run the caculation
void Caculate(int n,int k,int **state,int **distance,int** edge,int *result)
{
	int i,j,m;
	int t = n;
	int tmp;
	tmp = state[k][0];

	for(i = k - 1;i >= 1;i--)
	{
		j = 0;
		//check for state
		while (state[i][j])
		{
			m = 0;
			distance[i][j] = numeric_limits<int>::max();
			if (edge[state[i][j]][tmp] == numeric_limits<int>::max())
				while(state[i+1][m])
				{
					if (edge[state[i][j]][state[i+1][m]] != 
						numeric_limits<int>::max())
					{
						if (distance[i][j] > (distance[i+1][m] 
							+ edge[state[i][j]][state[i+1][m]]))
						{
							distance[i][j] = distance[i+1][m] + edge[state[i][j]][state[i+1][m]];
							result[state[i][j]] = state[i+1][m];
							t--;
						}
					}
					m++;
				}
			else
				while (state[i+1][m])
				{
					if (distance[i][j] > (distance[i+1][m]
						+ edge[state[i][j]][state[i+1][m]]))
					{
						distance[i][j] = distance[i+1][m] + 
						edge[state[i][j]][state[i+1][m]];
						result[state[i][j]] = state[i+1][m];
						t--;
					}
					m++;
				}
			j++;
		}
	}
	//reset
	t = 0;
	result[t] = 1;
	t = result[t];
	while(t < n)
	{
		cout << result[t] << " ";
		t = result[t];
	}
	cout << endl;
	cout << edge[i+1][0] << endl;
}

int main(int argc,char *argv[])
{
	int i,j;
	int** edge,**state,**distance;
	int n,k;
	int* result;
	cin >> n;
	cin >> k;

	edge = new int*[n+1];
	for(i = 0;i < n+1;i++)
	{
		edge[i] = new int[n+1];
		for(j = 0;j < n+1;j++)
			edge[i][j]=numeric_limits<int>::max();
	}

	state = new int*[n+1];
	for(i = 0;i < n+1;i++)
		state[i] = new int[n+1];
	distance = new int*[n+1];

	for (i = 0;i < n+1;i++)
	{
		distance[i] = new int[n+1];
		for (j = 0;j < n+1;j++)
			distance[i][j]=0;
	}
	result = new int[n+1];

	InitGraph(n,k,state,edge);
	Caculate(n,k,state,distance,edge,result);

	return 0;
}