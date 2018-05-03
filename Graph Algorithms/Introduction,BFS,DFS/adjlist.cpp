#include <bits/stdc++.h>

using namespace std;


void addEdge(vector<int> adj[],int v, int n)
{
    adj[v].push_back(n);
    adj[n].push_back(v);
}

void printGraph(vector<int> adj[], int n)
{
    int j=0;
    for(j=0;j<n;j++)
    {
        vector<int> :: iterator i;
        for(i=adj[j].begin();i!=adj[j].end();i++)
        {
            cout << *i << " " ;
        }
        cout<<endl;
    }
}

int main()
{
    int n=5;
    vector<int> adj[n];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    printGraph(adj,n);
}