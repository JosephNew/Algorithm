#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Element
{
public:
	Element(int id,double d)
		:_id(id),_d(d)
	{ }

	bool operator<(const Element& other)
	{
		return this->_d < other._d;
	}
	bool operator==(const Element& other)
	{
		return this->_d == other._d;
	}
	int _id;
	double _d;
};


vector<double> p;
vector<double> w;
double c;
int n;
double cw;
double cp;
double bestp;

double Bound(int i)
{
	double cleft = c - cw;
	double bound = cp;
	while(i <= n && w[i] <= cleft)
	{
		cleft -= w[i];
		bound += p[i];
		i++;
	}
	if(i <= n)
		bound += p[i]*cleft/w[i];
	return bound;
}

void Backtrace(int i)
{
	if(i > n)
	{
		bestp = cp;
		return;
	}
	if(cw + w[i] <= c)
	{
		cw += w[i];
		cp += p[i];
		Backtrace(i+1);
		cw -= w[i];
		cp -= p[i];
	}
	if(Bound(i+1) > bestp)
		Backtrace(i+1);
}

double Knapsack(vector<double>& pp,vector<double>& ww,double cc)
{
	c = cc;
	n = pp.size() - 1;
	cw = 0.0;
	cp = 0.0;
	bestp = 0.0;

	vector<Element> q;
	for(int i = 1;i <= n;i++)
		q.emplace_back(i,pp[i]/ww[i]);
	sort(q.begin(),q.end());
	reverse(q.begin(),q.end());
	vector<double> p;
	p.reserve(n+1);
	vector<double> w;
	w.reserve(n+1);
	for(int i = 1;i <= n;i++)
	{
		p[i] = pp[q[n-i].id];
		w[i] = ww[q[n-i].id];
	}
	Backtrace(1);
	return bestp;
}

int main()
{
	int num;
	cin >> num;
	int tmp = num;
	vector<double> ppp;
	vector<double> www;
	while(num--)
	{
		int v,w;
		cin >> v >> w;
		ppp.push_back(v);
		www.push_back(w);
	}
	cout << Knapsack(ppp,www,100) << endl;
	return 0;
}