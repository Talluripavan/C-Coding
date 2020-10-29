#include<bits/stdc++.h>

using namespace std;
void DFSSSSSSS(int s,vector<int> vv[], bool visit[]){
    
    visit[s]=true;
    cout<<s<<" ";
    
    for(auto i:vv[s]){
        
        if(!visit[i])
            DFSSSSSSS(i,vv,visit);
        
    }
    
}

int main(){
    
    int n=4;
    int e=5;
    
    vector<int> vv[n];
    bool visit[n];
    
    memset(visit,false,sizeof(n));
    
    for(int i=1;i<=n;i++){
        int u,v;
        cout<<"enter edge u,v"<<endl;
        cin>>u;
        cin>>v;
        vv[u].push_back(v);
        vv[v].push_back(u);
    }
    DFSSSSSSS(2,vv,visit);
    
    
    
    return 0;
}