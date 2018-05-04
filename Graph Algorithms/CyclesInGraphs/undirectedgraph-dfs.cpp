#include<bits/stdc++.h>
using namespace std;

class Graph 
{
    int V;
    list<int> *adj;

    bool isCycleUtil(int v, bool visited[], int parent[])
    {
        visited[v] = true;
        
        list<int> :: iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++)
        {
            parent[*i] = v;
            if(!visited[*i])
                if(isCycleUtil(*i,visited,parent))
                    return true;
            else if(parent[v]!=*i)
                return true;
        }
        return false;
    }

    public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int x,int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool isCycle()
    {
        bool visited[V];
        int parent[V];
        for(int i=0;i<V;i++)
        {
            visited[i] = false;
            parent[i] = -1;
        }

        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                if(isCycleUtil(i,visited,parent))
                    return true;
        }
        return false;
    }

};

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(1, 4);
    g.addEdge(2, 0);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    if(g.isCycle())
        cout<<"Cycle exists\n";
    else   
        cout<<"No cycle\n";

    return 0;
}