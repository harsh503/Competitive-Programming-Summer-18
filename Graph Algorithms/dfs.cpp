#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);

    public:
    Graph(int v);
    void addEdge(int u, int v);
    void DFS(int s);

};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int u, int x)
{
    adj[u].push_back(x);
}

void Graph::DFSUtil(int s, bool visited[])
{
    visited[s] = true;
    cout<<s<<" ";

    list<int> :: iterator i;
    for(i=adj[s].begin();i!=adj[s].end();i++)
    {
        if(!visited[*i])
        {
            DFSUtil(*i,visited);
        }
    }
}

void Graph::DFS(int s)
{
    bool *visited = new bool[v];

    for(int i=0;i<v;i++)
        visited[i] = false;

    DFSUtil(s,visited);

}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.DFS(2);

    return 0;
}