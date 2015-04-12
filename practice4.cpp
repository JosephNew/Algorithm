#include <iostream>
#include <utility>
#include <random>

void Merge(int lhs[],int rhs[],int m,int n,int result[])
{
	int k = 0;
    int l = 0,r = 0;
    //开始合并
    while(l < m && r < n)
    {
        if(lhs[l] > rhs[r])
        	result[k++] = lhs[l++];
        else
            result[k++] = rhs[r++];
    }
    while(l < m)
        result[k++] = lhs[l++];
    while(r < n)
        result[k++] = rhs[r++];
}

int main(int argc,char** argv)
{
	if(argc < 5)
	{
		std::cout << "usage: <m> <n> <k>";
		exit(1);
	}
	default_random_engine engine;
    uniform_int_distribution<int> u(1,1000);

	int m = std::stoi(argv[1]);
	int n = std::stoi(argv[2]);
	int k = std::stoi(argv[3]);

	int* lhs = new int[m];
	for(int i = 0;i < m;i++)
		lhs[i] = u(engine);
	int* rhs = new int[n];
	for(int i = 0;i < n;i++)
		rhs[i] = u(engine);
	int* result = new int[17];
	Merge(lhs,rhs,10,7,result);
	std::cout << 
	return 0;
}