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
        {
            if(!visited[*i])
                DFSUtil(*i,visited);
        }
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
    void countNodes()
    {
        bool visited[V];
        for(int i=0;i<V;i++)
            visited[i] = false;
        
        int count=0;
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {    
                DFSUtil(i,visited);
                count++;
            }        
        }

        cout<<count<<endl;
    }
};

int main()
{
    Graph g(8);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(3,4);
    g.addEdge(5,6);
    g.addEdge(0,7);

    g.countNodes();
    return 0;
}