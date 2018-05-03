#include<bits/stdc++.h>

using namespace std;

void bfs(int j1, int j2, int t)
{
    map<pair<int,int> , int> m;
    bool flag = false;
    vector<pair<int, int> > path;   
    queue<pair<int, int> > q;
    q.push({0,0});

    while(!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();

        if(m[{u.first,u.second}]==1)
            continue;
        
        if(u.first>j1 || u.second>j2 || u.first<0 || u.second<0)
            continue;

        path.push_back({u.first,u.second});
        m[{u.first,u.second}]=1;

        if(u.first==t || u.second==t)
        {
            flag = true;
            if(u.first==t)
            {
                if(u.second!=0)
                    path.push_back({u.first,0});
            }
            else
            {
                if(u.first!=0)
                    path.push_back({0,u.second});
            }
            int s = path.size();
            for(int i=0;i<s;i++)
                cout<<path[i].first<<","<<path[i].second<<endl;
            break;
        }

        q.push({u.first,j2});
        q.push({j1,u.second});

        for(int i=0;i<=max(j1,j2);i++)
        {
            int c,d;
            c = u.first+i;
            d = u.second-i;

            if(c==j1 || (d==0 && d>=0))
                q.push({c,d});

            c = u.first-i;
            d = u.second+i;

            if((c==0 && c>=0) || d==j1)
                q.push({c,d});
        }
        q.push({j1,0});
        q.push({0,j2});
    }

    if(!flag)
        cout<<"NO SOLUTION"<<endl;
    else
        cout<<"SOLUTION OBTD"<<endl;
}

int main()
{
    int j1=4,j2=3,t=2;
    cout<<"PATH\n";
    bfs(j1,j2,t);
    return 0;
}