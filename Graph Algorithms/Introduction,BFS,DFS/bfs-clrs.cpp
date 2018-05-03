#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> v[],int x, int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}

void BFS(vector<int> v[],int n, int s)
{
    int colour[n];
    int dist[n];
    int parent[n];
    for(int i=0;i<n;i++)
    {
        colour[i] = 0;
        parent[i] = -1;
        dist[i] = 0;
    }    

    queue<int> q;
    q.push(s);
    dist[s] = 0;
    colour[s] = 1;
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        cout<<p<<" ";
        
        vector<int> :: iterator i;
        for(i=v[p].begin();i!=v[p].end();i++)
        {
            if(colour[*i]==0)
            {
                parent[*i] = p;
                colour[*i] = 1;
                dist[*i] = dist[p] + 1;
                q.push(*i);
            }
        }

        colour[p] = 2;
    }
}

int main()
{
    int n=7;
    vector<int> v[n];
    addEdge(v, 0, 3);
    addEdge(v, 0, 5);
    addEdge(v, 5, 2);
    addEdge(v, 5, 4);
    addEdge(v, 3, 1);
    addEdge(v, 3, 6);

    int s=0;
    BFS(v,n,s);
    cout<<endl;
    return 0;
}