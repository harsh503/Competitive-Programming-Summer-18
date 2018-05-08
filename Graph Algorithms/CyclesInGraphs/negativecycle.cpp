#include<bits/stdc++.h>
using namespace std;

class Graph 
{
    int V,E;
    vector<pair<int,pair<int, int> > > edgelist;

    public:
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }
    void addEdge(int u, int v, int w)
    {
        edgelist.push_back(make_pair(w,make_pair(u,v)));
    }
    bool isCycle(int src)
    {
        int dist[V];
        for(int i=0;i<V;i++)
            dist[V] = INT_MAX;
        
        dist[src] = 0;

        for(int i=1;i<=V-1;i++)
        {
            for(int j=0;j<E;j++)
            {
                int w = edgelist[j].first;
                int u = edgelist[j].second.first;
                int v = edgelist[j].second.second;
                if(dist[u]!=INT_MAX && dist[v]>dist[u]+w)
                    dist[v] = dist[u] + w;
            }
        }

        for(int j=0;j<E;j++)
        {
            int w = edgelist[j].first;
            int u = edgelist[j].second.first;
            int v = edgelist[j].second.second;        
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
                return true;
        }
        return false;
    }
};

int main()
{
//    Graph g(5,8);
//    g.addEdge(0,1,-1);
//    g.addEdge(0,2,4);
//    g.addEdge(1,2,3);
//    g.addEdge(1,3,2);
//    g.addEdge(1,4,2);
//    g.addEdge(3,2,5);
//    g.addEdge(3,1,1);
//    g.addEdge(4,3,-3);

    Graph g(4,4);
    g.addEdge(0,1,1);
    g.addEdge(1,2,-1);
    g.addEdge(2,3,-1);
    g.addEdge(3,0,-1);

    if(g.isCycle(0))
        cout<<"Negative Cycle Exists\n";
    else 
        cout<<"Negative Cycle doesn't Exist\n";

    return 0;
}