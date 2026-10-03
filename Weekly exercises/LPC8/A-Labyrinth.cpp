#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<string> g(n);
    for(auto &s:g) cin>>s;
    queue<pair<int,int>> q;
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
    vector<vector<char>> step(n,vector<char>(m));
    int sx,sy,ex,ey;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='A') sx=i,sy=j;
            if(g[i][j]=='B') ex=i,ey=j;
            }
    }
    q.push({sx,sy});
    vis[sx][sy]=1;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    char dc[4]={'D','U','R','L'};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(!vis[nx][ny] && g[nx][ny]!='#'){
                    vis[nx][ny]=1;
                    parent[nx][ny]={x,y};
                    step[nx][ny]=dc[i];
                    q.push({nx,ny});
                }
        }
        }
    }
    if(!vis[ex][ey]){
        cout<<"NO\n";
        return 0;
    }
    string path;
    int x=ex,y=ey;
    while(x!=sx || y!=sy){
        path.push_back(step[x][y]);
        int px = parent[x][y].first;
        int py = parent[x][y].second;
        x=px; 
        y=py;
    }
    reverse(path.begin(),path.end());
    cout<<"YES\n";
    cout<<path.size()<<"\n";
    
    cout<<path<<"\n";

    



}