#include<bits/stdc++.h>
using namespace std;

int solve(int A[],int n)
{
    int parent[n+1];
    int visit[n+1];
    int i,j,count=0;

    for(i=0;i<n+1;i++)
    {
        parent[i] = -1;
        visit[i] = 0;
    }

    for(i=0;i<n;i++)
    {
        j=i;

        if(parent[j]==-1)
        {
            while(parent[j]==-1)
            {
                parent[j] = i;
                j = (j+A[j]+1)%n;
            }
            if(parent[j]==i)
            {
                while(!visit[j])
                {
                    visit[j]=1;
                    j = (j+1+A[j])%n;
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    int A[] = {1,1,1,1};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<solve(A,n)<<endl;
    return 0;
}