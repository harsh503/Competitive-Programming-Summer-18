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
    int addEdge(int x,int y)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int bfs(int x, int y)
    {
        int visited[V];
        for(int i=0;i<V;i++)
            visited[i] = 0;
        queue<int> q;
        q.push(x);
        visited[x]=1;
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            list<int> :: iterator i;
            for(i=adj[p].begin();i!=adj[p].end();i++)
            {
                if(!visited[*i])
                {
                    visited[*i] = visited[p]+1;
                    q.push(*i);
                }
                if(*i == y)
                    return(visited[*i]-1);
            }
        }
    }
    
};

void sieve(vector<int>& pset)
{
    int n=9999;
    bool prime[n+1];
    for(int i=0;i<n+1;i++)
    {
        prime[i] = true;
    }

    for(int i=2;i*i<=n;i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                prime[j] = false;
            }
        }
    }
    for(int p=1000;p<=n;p++)
    {   
        if(prime[p])
        {
            pset.push_back(p);

        }    
    }
}

bool compare(int n1, int n2)
{
    stringstream ss1;
    ss1 << n1;
    string s1 = ss1.str();
    stringstream ss2;
    ss2 << n2;
    string s2 = ss2.str();

    int c=0;
    if(s1[0]!=s2[0])
        c++;
    if(s1[1]!=s2[1])
        c++;
    if(s1[2]!=s2[2])
        c++;
    if(s1[3]!=s2[3])
        c++;

    return (c==1);
}

int shortestPath(int n1, int n2)
{
    vector<int> pset;
    sieve(pset);

    Graph g(pset.size());
    for(int i=0;i<pset.size();i++)
        for(int j=i+1;j<pset.size();j++)
            if(compare(pset[i],pset[j]))
                g.addEdge(i,j);

   int in1, in2;
    for(int i=0;i<pset.size();i++)
        if(pset[i]==n1)
            in1 = i;
    for(int i=0;i<pset.size();i++)
        if(pset[i]==n2)
            in2 = i;

    return g.bfs(in1,in2);
}

int main()
{
    int num1 = 1033, num2 = 8179;
    cout << shortestPath(num1, num2) <<endl;
    return 0;
}