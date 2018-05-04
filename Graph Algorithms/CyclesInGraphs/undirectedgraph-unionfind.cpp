#include<bits/stdc++.h>
using namespace std;

class Graph 
{
    int V;
    list<int> *adj;

    int find(int parent[], int x)
    {
        if(parent[x]==-1)
            return x;
        return find(parent,parent[x]);
    }
    void Union(int parent[], int x, int y)
    {
        int xp = find(parent, x);
        int yp = find(parent, y);

        parent[xp] = yp;
    }

    public:
    Graph(int v)
    {
        this->V = v;
        adj = new list<int>[V];
    }
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool isCycle()
    {
        bool visited[V][V];
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                visited[i][j] = false;



        int parent[V];
        for(int i=0;i<V;i++)
            parent[i] = -1;

        for(int i=0;i<V;i++)
        {
            list<int> :: iterator z;
            for(z=adj[i].begin();z!=adj[i].end();z++)
            {
                if(visited[i][*z]==false)
                {
                    visited[i][*z]=true;
                    visited[*z][i]=true;

                    int x,y;
                    x = find(parent, i);
                    y = find(parent, *z);
                    if(x==y)
                        return true;
                    
                    Union(parent, x, y);
                }
            }
        }
        return false;
    }

};

int main()
{  
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    if(g.isCycle())
        cout<<"Cycle found\n";
    else   
        cout<<"No cycles\n";

    return 0;
}