#include<bits/stdc++.h>
using namespace std;

class Graph 
{
    int V;
    list<int> *adj;

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
    void bfs(int s)
    {
        bool visited[V];
        int level[V];
        for(int i=0;i<V;i++)
        {
            visited[i] = false;
            level[i] = 0;
        }
        
        queue<int> q;
        q.push(s);

        level[s]=0;
        while(!q.empty())
        {
            int z = q.front();
            q.pop();
            visited[z] = 1;

            list<int> ::iterator i;
            for(i=adj[z].begin();i!=adj[z].end();i++)
            {
                if(!visited[*i])
                {
                    level[*i] = level[z]+1;
                    q.push(*i);
                }
            }
        }

        cout<<"Levels\n";
        for(int i=0;i<V;i++)
            cout<<i<<"->"<<level[i]<<endl;
    }
};

int main()
{
    Graph g(8);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(2,5);
    g.addEdge(2,6);
    g.addEdge(6,7);
    
    int s=0;
    g.bfs(s);
}