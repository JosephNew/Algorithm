#include <iostream>
const int Num = 5;
struct Graph         
{
    char vertex[Num];  
    int edges[Num][Num];
    int vertexNum;
    int edgeNum;
}; 

void Floyd(Graph g)
{
 　　int i,j,k;
    int data[Num][Num];
 　　int path[Num][Num];
    int n = g.vertexNum;
    //initialize
 　　for(i = 0;i < n;i++)
    　　for(j = 0;j < n;j++)
    　　{ 　　
             data[i][j] = g.edges[i][j];
         　　 path[i][j] = -1;
     　 }
 　　for(k = 0;k < n;k++)
        for(i = 0;i < n;i++)
            for(j = 0;j < n;j++)
                if(data[i][j] > (data[i][k] + data[k][j]))
             　　{
                   　　data[i][j] = data[i][k] + data[k][j];
                   　　path[i][j] = k;
              　 }
    for(int i = 0;i < Num;i++)
        for(int j = 0;j < Num;j++)
            cout << data[i][j] << endl;
}

int main()
{
    vector<int> graph;
    int num;
    cin >> num;
    for(int i = 0;i < num;i++)
        for(int j = 0;j < num;j++)
        {
            int tmp;
            cin >> tmp;
            graph.push_back(tmp);
        }
    Floyd(graph);
    return 0;
}