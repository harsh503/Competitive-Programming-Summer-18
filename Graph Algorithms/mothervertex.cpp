#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    void DFSUtil(int v, bool visited[])
    {
        visited[v] = true;
        list<int> :: iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++)
            if(!visited[*i])
                DFSUtil(*i,visited);
    }

    public:
    Graph(int v)
    {
        this->V = v;
        adj = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    int mothervertex()
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
            visited[i] = false;

        int lv=0;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                DFSUtil(i,visited);
                lv = i;
            }
        }

        for(int i=0;i<V;i++)
            visited[i] = false;

        DFSUtil(lv,visited);
        for(int i=0;i<V;i++)
            if(visited[i]==false)
                return -1;

        return lv;
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);

    cout<<g.mothervertex()<<endl;

    return 0;
}
