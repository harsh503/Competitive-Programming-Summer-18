#include<bits/stdc++.h>
using namespace std;

void dfs(int parent, int ans[], vector<int> v[])
{
    ans[parent] = 1;
    for(int i=0;i<v[parent].size();i++)
    {
        if(!ans[v[parent][i]])
        {
            dfs(v[parent][i],ans,v);
        }    
    }
}

void binaryPalindrome(int n, int k)
{
    int arr[n], result[n];

    vector<int> v[k];
    for(int i=0;i<n;i++)
    {
        arr[i] = i%k;
        result[i] = 0;
    }    
    
    for(int i=0;i<n/2;i++)
    {
        v[arr[i]].push_back(arr[n-i-1]);
        v[arr[n-i-1]].push_back(arr[i]);
    }

    dfs(0,result,v);

    for(int i=0;i<n;i++)
        cout<<result[arr[i]];
    cout<<endl;
}

int main()
{
    int n=10,k=4;
    binaryPalindrome(n,k);
    return 0;
}