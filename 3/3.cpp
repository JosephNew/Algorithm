#include <iostream>
#include <vector>
#include <limits>
using namespace std;
using Graph = vector<vector<int>>;
struct Vertex
{
	Vertex()
		:_d(numeric_limits<int>::max()),
		_prev(nullptr)
	{ }
	int _d;
	Vertex* _prev;
	int f(){return 1;}
};

int GetWeight(const Graph& graph,unsigned int li,unsigned int ri)
{
	return graph[li][ri];
}

void Relax(Vertex* u,Vertex* v,int w)
{
	if(v->_d > u->_d + w)
	{
		v->_d = u->_d + w;
		v->_prev = u;
	}
}

void SingleShortestPath(vector<Vertex*>& v,const Graph& graph)
{
	for(int i = 0;i < graph.size() - 1;i++)
		for(int i = 0;i < graph.size();i++)
			for(int j = 0;j < graph.size();j++)
				Relax(v[i],v[j],GetWeight(graph,j,i));
	//check for negative weighted loop
	for(int i = 0;i < graph.size();i++)
			for(int j = 0;j < graph.size();j++)
				if(v[i]->_d > v[j]->_d + GetWeight(graph,j,i))
					cout << "false" << endl;
				else
					for(Vertex* p : v)
					{
						int tmp = p->_d;
						cout << tmp << endl;
					}
}

int main()
{
	Graph g;
	unsigned int num;
	cin >> num;
	for(int i = 0;i < num;i++)
	{
		g.emplace_back(num);
		for(int j = 0;j < num;j++)
		{
			int tmp;
			cin >> tmp;
			g[i].push_back(tmp);
		}
	}
	vector<Vertex*> vertex;
	for(int i = 0;i < num;i++)
		vertex.push_back(new Vertex());
	SingleShortestPath(vertex,g);
	return 0;

}