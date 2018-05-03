#include<bits/stdc++.h>
using namespace std;

class Graph 
{
    int V;
    list<int> *adj;
    int *level;

    public:
    Graph(int v)
    {
        this->V = v;
        adj = new list<int>[V];
        level = new int[V];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void BFS(int s,int lvl)
    {
        bool visited[V];
        for(int i=0;i<V;i++)
            visited[i] = false;

        list<int> Q;
        Q.push_back(s);

        level[s]=0;

        int l = 0;

        while(!Q.empty())
        {
            int n = Q.front();
            Q.pop_front();

            visited[n] = true;
            if(l==level[n])
                l++;
            list<int> :: iterator i;
            for(i=adj[n].begin();i!=adj[n].end();i++)
            {
                if(!visited[*i])
                {
                    Q.push_back(*i);
                    level[*i]=l;
                }
            }
        }
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(level[i]==lvl)
                count++;
        }
        cout<<count<<endl;
    }
};

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.BFS(0,2);
    return 0;
}