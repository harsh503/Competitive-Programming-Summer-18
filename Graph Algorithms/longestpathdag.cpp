#include<bits/stdc++.h>
using namespace std;

class AdjListNode
{
    int v;
    int w;
    public:
    AdjListNode(int x, int y){v=x; w=y;}
    int getV() {return v;}
    int getW() {return w;}
};

class Graph
{
    int V;
    list<AdjListNode> *adj;

    void TopologicalSortUtil(int v, bool visited[], stack<int> &Stack)
    {
        visited[v] = true;
        list<AdjListNode> :: iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++)
        {   
            AdjListNode node = *i; 
            if(!visited[node.getV()])
                TopologicalSortUtil(node.getV(),visited,Stack);
        }
        Stack.push(v);
    }

    public:
    Graph(int v)
    {
        this->V = v;
        adj = new list<AdjListNode>[V];
    }
    void addEdge(int u, int v, int w)
    {
        AdjListNode node(v,w);
        adj[u].push_back(node);
    }
    void longestPath(int s)
    {
        stack<int> Stack;
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
            visited[i] = false;

        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
                TopologicalSortUtil(i,visited,Stack);
        }

        int dist[V];
        for(int i=0;i<V;i++)
        {
            dist[i] = INT_MIN;
        }

        dist[s] = 0;

        while(!Stack.empty())
        {
            int u = Stack.top();
            Stack.pop();
            list<AdjListNode> :: iterator i;
            if(dist[u]!=INT_MIN)
            {
                for(i=adj[u].begin();i!=adj[u].end();i++)
                {
                    if(dist[i->getV()] < dist[u] + i->getW())
                    {
                        dist[i->getV()] = dist[u] + i->getW();
                    }
                }
            }
        }

        for(int i=0;i<V;i++)
            if(dist[i]==INT_MIN)
                cout<<"INF ";
            else
                cout<<dist[i]<<" ";

    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.longestPath(1);

    return 0;
}