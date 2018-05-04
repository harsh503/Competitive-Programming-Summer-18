#include<bits/stdc++.h>
using namespace std;

class Graph 
{
    int V;
    list<int> *adj;

    bool isCyclicUtil(int v, bool visited[], bool recStack[])
    {
        if(visited[v]==false)
        {
            visited[v]=true;
            recStack[v]=true;
            list<int> :: iterator i;
            for(i=adj[v].begin();i!=adj[v].end();i++)
            {
                if(!visited[*i] && isCyclicUtil(*i,visited,recStack))
                {
                    return true;
                }
                else if (recStack[*i])
                    return true;
            }
        }
        recStack[v]=false;
        return false;
    }

    public:
    Graph(int v)
    {
        this->V = v;
        adj = new list<int>[V];
    }
    int addEdge(int x, int y)
    {
        adj[x].push_back(y);
    }
    bool isCyclic()
    {
        bool visited[V];
        bool recStack[V];
        for(int i=0;i<V;i++)
        {
            visited[i] = false;
            recStack[i] = false;
        }
        for(int i=0;i<V;i++)
        {
            if(isCyclicUtil(i,visited,recStack))
                return true;
        }
        return false;
    }
};


int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
 
    if(g.isCyclic())
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";
    return 0;
}