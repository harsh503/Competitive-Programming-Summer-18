#include<bits/stdc++.h>
using namespace std;

class Graph 
{
    int V;
    list<int> *adj;

    void topologicalSortUtil(int v, bool visited[], stack<int> &S)
    {
        visited[v] = true;
        list<int> :: iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++)
        {
            if(!visited[*i])
                topologicalSortUtil(*i,visited,S);
        }
        S.push(v);
    }

    public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
    }
    void topologicalSort()
    {
        bool visited[V];
        for(int i=0;i<V;i++)
            visited[i] = false;

        stack<int> S;

        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                topologicalSortUtil(i,visited,S);
        }

        while(!S.empty())
        {
            cout<<S.top()<<" ";
            S.pop();
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    g.topologicalSort();
    cout<<endl;
    return 0;
}