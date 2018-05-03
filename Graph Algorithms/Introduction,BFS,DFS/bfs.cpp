#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int v;
    list<int> *adj;
    
    public:
    Graph(int v);
    void addEdge(int v, int u);
    void BFS(int s);
};

Graph::Graph(int v)
{
    this->v = v;
    adj = new list<int>[v];
}

void Graph::addEdge(int v, int u)
{
    adj[v].push_back(u);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[v];
    for(int i=0;i<v;i++)
        visited[i] = false;

    visited[s] = true;

    list<int> queue;
    queue.push_back(s);

    while(!queue.empty())
    {
        int x;
        x = queue.front();
        queue.pop_front();
        cout<<x<<" ";
        
        list<int> :: iterator z;
        for(z=adj[x].begin();z!=adj[x].end();z++)
        {
            if(!visited[*z])
            {
                visited[*z] = true;
                queue.push_back(*z);
            }    
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(2);

    return 0;
}