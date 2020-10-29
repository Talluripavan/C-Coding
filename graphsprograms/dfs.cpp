#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

void dfs(int s, vector<int> g[], bool vis[])
{
    vis[s]=true;
    cout<<s<<" ";
    for(auto x:g[s])
    {
        if(!vis[x])
        {
            dfs(x,g,vis);
        }
    }
    // Your code here
}


int main()
{
        cout<<"enter total nodes"<<endl;

        int N, E;
        cin>>N;
        cout<<"enter total edges"<<endl;
        cin>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=1;i<=E;i++)
        {
            int u,v;
            cout<<"enter edge u and v :"<<" ";
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        cout<<"enter a node from which u want to implement dfs"<<endl;
        int t;
        cin>>t;
        cout<<"\n";
        cout<<"The DFS order is"<<endl;
        dfs(t,g,vis);
        
        cout<<endl;
    
}
