#include<bits/stdc++.h>
using namespace std; 

int main(){
    int n,m;// n->no of nodes, m->no of edges
    cout<<"Enter no of nodes and no of edges respectively: "; 
    cin>>n>>m;  
    vector<int>adj[n+1]; 
    vector<int>indegrees(n+1,0); 
    for(int i=0;i<m;i++){
        int u,v; 
        cin>>u>>v; 
        adj[u].push_back(v); 
        indegrees[v]++; 
    }

    vector<int>ans;  
    queue<int>q; 
    for(int i=0;i<n;i++){
        if(indegrees[i]==0){
            q.push(i); 
        }
    }

    while(q.empty()==false){
        int node=q.front(); 
        q.pop(); 
        ans.push_back(node); 
        for(auto &it:adj[node]){
            indegrees[it]--; 
            if(indegrees[it]==0){
                q.push(it); 
            }
        }
    }
    for(auto &it:ans){
        cout<<it<<" "; 
    }
    cout<<endl; 


}