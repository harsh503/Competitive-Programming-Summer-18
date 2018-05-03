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
    void countPathsUtil(int s, int d, bool visited[],int &count)
    {
        visited[s]=true;
        if(s==d)
        {   
            count++;
        }
        else
        {
            list<int> :: iterator i;
            for(i=adj[s].begin();i!=adj[s].end();i++)
            {
                if(!visited[*i])
                {
                    countPathsUtil(*i,d,visited,count);
                }
            }
        }
        visited[s] = false;
    }
    int countPaths(int s, int d)
    {
        bool visited[V];
        for(int i=0;i<V;i++)
            visited[i] = false;

        int count=0;
        countPathsUtil(s,d,visited,count);
        return count;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 4);
    g.addEdge(1, 4);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 2);

    int s=0,d=4;
    cout<<g.countPaths(s,d)<<endl;

    return 0;
}