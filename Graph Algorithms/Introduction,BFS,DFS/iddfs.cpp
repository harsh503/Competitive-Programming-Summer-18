#include<bits/stdc++.h>
using namespace std;

class Graph 
{
    int V;
    list<int> *adj;

    bool DLS(int src, int target, int limit)
    {
        if(src==target)
            return true;
        
        if(limit<=0)
            return false;
        
        list<int> :: iterator i;
        for(i=adj[src].begin();i!=adj[src].end();i++)
        {
            if(DLS(*i,target,limit-1)==true)
                return true;
        }
        return false;
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
    }

    bool IDDFS(int src, int target, int max_depth)
    {
        for(int i=0;i<max_depth;i++)
        {
            if(DLS(src,target,i)==true)
                return true;
        }
        return false;
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
 
    int target = 6, maxDepth = 3, src = 0;
    if (g.IDDFS(src, target, maxDepth) == true)
        cout << "Target is reachable from source "
                "within max depth\n";
    else
        cout << "Target is NOT reachable from source "
                "within max depth\n";
    return 0;
}