#include<bits/stdc++.h>
using namespace std;
const int N= 1e+3;
vector<int>adj[N];

//component
vector<int>cmp;
//visited array
bool visited[N];
//dfs implementation
void dfs( int s){
    visited[s]=true;
    cmp.push_back(s);
    for(int v: adj[s]){
        if(visited[v]) continue;
        dfs(v);
    }
    
}

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>ans;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            ans.push_back(i);
        }

    }

    cout<<ans.size()-1<<endl;
    for(int i=0; i<ans.size()-1; i++){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    return 0;
}