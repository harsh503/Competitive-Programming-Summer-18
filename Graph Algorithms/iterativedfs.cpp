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
    }
    void DFS(int s)
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
            visited[i] = false;

        stack<int> Stack;
        Stack.push(s);

        while(!Stack.empty())
        {
            int z = Stack.top();
            Stack.pop();

            if(!visited[z])
            {
                cout<<z<<" ";
                visited[z]=true;
            }

            list<int> :: iterator i;
            for(i=adj[z].begin();i!=adj[z].end();i++)
            {
                if(!visited[*i])
                    Stack.push(*i);
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.DFS(0);
    cout<<endl;
    
    return 0;
}