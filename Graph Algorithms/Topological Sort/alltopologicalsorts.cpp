#include<bits/stdc++.h>
using namespace std;

class Graph 
{
    int V;
    list<int> *adj;
    vector<int> indegree;

    void allTopologicalSortsUtil(vector<int> &res, bool visited[])
    {
        bool flag = false;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0 && !visited[i])
            {
                list<int> :: iterator j;
                for(j=adj[i].begin();j!=adj[i].end();j++)
                {
                    indegree[*j]--;
                }
                res.push_back(i);
                visited[i] = true;
                allTopologicalSortsUtil(res,visited);

                visited[i] = false;
                res.erase(res.end()-1);
                for(j=adj[i].begin();j!=adj[i].end();j++)
                    indegree[*j]++;

                flag = true;
            }
        }
        if(!flag)
        {
            for(int i=0;i<res.size();i++)
            {
                cout<<res[i]<<" ";
            }
            cout<<endl;
        }
    }

    public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
        for(int i=0;i<V;i++)
            indegree.push_back(0);
    }
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
        indegree[y]++;
    }
    void allTopologicalSorts()
    {
        bool visited[V];
        for(int i=0;i<V;i++)
            visited[i] = false;

        vector<int> res;
        allTopologicalSortsUtil(res,visited);
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
 
    g.allTopologicalSorts();
    cout<<endl;
    return 0;
}