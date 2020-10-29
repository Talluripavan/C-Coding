
#include <iostream>
#include<vector>
using namespace std;
int Cyclicornot(int s,vector<int> g[],int v,int p,vector<bool>&vis){
    
    vis[s]=true;
    vector<int>&adj=g[s];
    for(int i=0;i<adj.size();i++){
        
        if(!vis[adj[i]]){
            if(Cyclicornot(adj[i],g,v,s,vis)==1)
            return 1;
        }
        else{
            if(adj[i]!=p)
            return 1;
        }
            
        
    }
    return 0;
}
int Iscyclic(vector<int> gg[],int v){
    vector<bool> visit(v,false);
    
    for(int i=0;i<v;i++){
        if(!visit[i])
        {
            if(Cyclicornot(i,gg,v,-1,visit)==1)
            return 1;
        }
    }
   return 0; 
}



int main()
{
    printf("Hello World");
    int v;
    cin>>v;
    vector<int> gg[v];
    
    int u,vv;
    for(int i=0;i<v;i++){
        cin>>u>>v;
        gg[u].push_back(vv);
        gg[vv].push_back(u);
    }

  if(Iscyclic(gg,v)==1)
  cout<<"Grraph is cyclic"<<endl;
  else
  cout<<"Grraph NOT cyclic"<<endl;
    return 0;
}
