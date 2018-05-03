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
    bool DFSUtil(int v, bool visited[], int degree[], int k)
    {
        visited[v] = true;
        list<int> :: iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++)
        {
            if(degree[v]<k)
            {
                degree[*i]--;
                //cout<<v<<*i<<"check1\n";   
            }    

            if(!visited[*i])
            {
                if(DFSUtil(*i, visited, degree, k))
                {
                    degree[v]--;
//                    cout<<v<<*i<<"check2\n";
                }
            }
        }
        return (degree[v]<k);
    }
    void addEdge(int x, int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    void kcores(int k)
    {
        bool *visited = new bool[V];
        for(int i=0;i<V;i++)
        {
            visited[i] = false;
        }

        int mindegree = INT_MAX;
        int degree[V];
        int startvertex;
        for(int i=0;i<V;i++)
        {
            degree[i] = adj[i].size();
            if(degree[i]<mindegree)
            {    
                mindegree = degree[i];
                startvertex = i;
            }
        }
//        cout<<startvertex<<endl;
        DFSUtil(startvertex,visited,degree,k);

        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                DFSUtil(i,visited,degree,k);
                cout<<"ok\n";
            }            
        }

//        for(int i=0;i<V;i++)
//            cout<<degree[i];

        cout<<"\nK-Cores\n";

        for(int i=0;i<V;i++)
        {
            if(degree[i]>=k)
            {
                cout<<"\n"<<i<<"-> ";
                list<int> :: iterator itr;
                for(itr=adj[i].begin();itr!=adj[i].end();itr++)
                {
                    if(degree[*itr]>=k)
                        cout<<" "<<*itr;
                }
            }

        }
    }
};

int main()
{
    int k=3;
    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.kcores(k);
 
    cout << endl << endl;
 
    Graph g2(13);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 3);
    g2.addEdge(1, 4);
    g2.addEdge(1, 5);
    g2.addEdge(1, 6);
    g2.addEdge(2, 7);
    g2.addEdge(2, 8);
    g2.addEdge(2, 9);
    g2.addEdge(3, 10);
    g2.addEdge(3, 11);
    g2.addEdge(3, 12);
    g2.kcores(k);

    return 0;
}