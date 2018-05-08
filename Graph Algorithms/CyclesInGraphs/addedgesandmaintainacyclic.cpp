#include<bits/stdc++.h>
using namespace std;

class Graph 
{
    int V;
    list<int> *adj;
    vector<pair<int,int> > edges;

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
    void addExtraEdges(int x, int y)
    {
        edges.push_back(make_pair(x,y));
    }
    void merge()
    {
        vector<int> tsort;

        bool visited[V];
        for(int i=0;i<V;i++)
            visited[i] = false;
        
        stack<int> S;

        for(int i=0;i<V;i++)
            if(!visited[i])
                topologicalSortUtil(i,visited,S);
    
        while(!S.empty())
        {
            tsort.push_back(S.top());
            S.pop();
        }
    
        for(int i=0;i<edges.size();i++)
        {
            int x = edges[i].first;
            int y = edges[i].second;
            
            for(int j=0;j<tsort.size();j++)
            {
                int z = tsort[j];
                if(z==x)
                {
                    adj[x].push_back(y);
                    break;
                }
                else if(z==y)
                {
                    adj[y].push_back(x);
                    break;
                }
            }
        }
    }

    void print()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->";
            list<int> :: iterator itr;
            for(itr=adj[i].begin();itr!=adj[i].end();itr++)
            {
                cout<<*itr<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0,5);
    g.addEdge(0,1);
    g.addEdge(5,1);
    g.addEdge(5,2);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(3,4);

    g.addExtraEdges(0,2);
    g.addExtraEdges(0,3);
    g.addExtraEdges(0,4);
    g.addExtraEdges(5,4);

    g.print();
    cout<<endl<<endl;

    g.merge();

    g.print();

    return 0;
}