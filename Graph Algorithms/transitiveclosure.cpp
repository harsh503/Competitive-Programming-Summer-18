#include<bits/stdc++.h>
using namespace std;

class Graph 
{
    int V;
    list<int> *adj;
    bool **tc;

    void DFSUtil(int x, int y)
    {
        tc[x][y] = true;
        list<int> :: iterator i;
        for(i=adj[y].begin();i!=adj[y].end();i++)
        {
            if(tc[x][*i]==false)
                DFSUtil(x,*i);
        }
    } 

    public:

    Graph(int v)
    {
        this->V = v;
        adj = new list<int>[v];
        tc = new bool*[v];
        for(int i=0;i<v;i++)
        {
            tc[i] = new bool[v];
            int j;
            for(j=0;j<V;j++)
                tc[i][j] = false;
        }
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void transitiveClosure()
    {
        for(int i=0;i<V;i++)
            DFSUtil(i,i);

        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
                cout<<tc[i][j]<<" ";
            cout<<endl;
        }
    }

};

int main()
{
    Graph g(4);
    //g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.transitiveClosure();

    return 0;
}