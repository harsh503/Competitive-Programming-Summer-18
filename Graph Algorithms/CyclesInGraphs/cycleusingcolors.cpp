#include<bits/stdc++.h>
using namespace std;

//This is for a directed graph only.

class Graph 
{
    int V;
    list<int> *adj;

    bool isCyclicUtil(int v, int colour[])
    {
        cout<<v<<"in\n";
        colour[v] = 1;
        list<int> :: iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++)
        {
            cout<<v<<" "<<*i<<"in\n";
            if(colour[*i]==1)
            {
                cout<<"in1\n";
                return true;
            }    
            if(colour[*i]==0 && isCyclicUtil(*i,colour))
            {
                cout<<"in2\n";
                return true;
            }
        }
        colour[v] = 2;
        return false;
    }

    public:
    Graph(int v)
    {
        this->V = v;
        adj = new list<int>[V];
    }
    int addEdge(int x, int y)
    {
        adj[x].push_back(y);
        
    }
    bool isCyclic()
    {
        int colour[V];
        for(int i=0;i<V;i++)
            colour[i] = 0;
        
        for(int i=0;i<V;i++)
        {
            if(colour[i]==0)
                if(isCyclicUtil(i,colour))
                {
                    cout<<"main\n";
                    return true;
                }    
        }
        return false;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
 //   g.addEdge(0, 2);
   // g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    if (g.isCyclic())
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";
 
    return 0;
}