#include<bits/stdc++.h>

using namespace std;

void BFSSSSS(int s,vector<int> vv[],bool visit[]){
    queue<int> qq;
    qq.push(s);
    visit[s]=true;
    
    while(!qq.empty()){
        int i=qq.front();
        cout<<i<<" ";
        qq.pop();
        vector<int> &m=vv[i];
        
        for(int j=0;j<m.size();j++){
            if(!visit[m[j]]){
                visit[m[j]]=true;
                qq.push(m[j]);
            }
        }
        
    }
}


int main(){
    
    int n=3;
    int e=3;
    
    vector<int> vv[n];
    bool visit[n];
    memset(visit,false,sizeof(n));
    
    for(int i=0;i<n;i++){
        cout<<"enter edge u and v :"<<" ";
        int u,v;
        cin>>u;
        cin>>v;
        vv[v].push_back(u);
        vv[u].push_back(v);
    }
    cout<<"BFS"<<endl;
    BFSSSSS(2,vv,visit);
    
    
    
    return 0;
}