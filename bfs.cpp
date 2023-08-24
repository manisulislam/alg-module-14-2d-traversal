#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
//global
int n, m;
//range
const int N= 1e+2;

//visited bool array
bool visited[N][N];

//distance array
int dist[N][N];

//validity check
bool isValid(int ni, int nj){
    return ( ni>=0 && ni<n&& nj>=0 && nj<m);

}
//direction
vector<pii>direct= {{-1,0},{1,0},{0,-1},{0,1}};
void bfs(int si, int sj){
    queue<pii>q;
    q.push({si, sj});
    dist[si][sj]=0;
    visited[si][sj]=true;
    while(!q.empty()){
        pii parent = q.front();
        int i= parent.first;
        int j= parent.second;
        q.pop();
        for(int k=0; k<4; k++){
            pii child=direct[k];
            int ni= i+child.first;
            int nj= j+child.second;
            if(isValid(ni, nj)&& !visited[ni][nj]){
                q.push({ni,nj});
                visited[ni][nj]=true;
                dist[ni][nj]= dist[i][j]+1;
            }
            

        }
    }

}
int main(){
    
    cin>>n>>m;
    char a[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    int si, sj;
    cin>>si>>sj;
    bfs(si,sj);
    //print
    for(int i=0; i<n;i++){
        for(int j=0; j<m; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}