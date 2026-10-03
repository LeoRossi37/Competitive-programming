#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<string> g(n);
    for(auto &s:g) cin>>s;
    vector<vector<int>> distM(n,vector<int>(m,1e9));
    queue<pair<int,int>> q;
    int sx,sy;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='M'){
                q.push({i,j});
                distM[i][j]=0;
            }
            if(g[i][j]=='A'){
                sx=i,sy=j;
            }
        }
    }
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};

    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];

            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(g[nx][ny]!='#' && distM[nx][ny]>distM[x][y]+1){
                    distM[nx][ny]=distM[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
    }
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
    vector<vector<char>> step(n,vector<char>(m));
    queue<pair<int,int>> q2;
    q2.push({sx,sy});
    vis[sx][sy]=1;
    int ex=-1, ey=-1;
    char dc[4]={'D','U','R','L'};
    while(!q2.empty()){
        int x=q2.front().first;
        int y=q2.front().second;
        q2.pop();
        if(x==0 || x==n-1 || y==0 || y==m-1){
            ex=x; ey=y;
            break;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i], ny=y+dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(!vis[nx][ny] && g[nx][ny]!='#'){
                    int next_time = distM[x][y] + 1;

                    if(next_time < distM[nx][ny]){
                        vis[nx][ny]=1;
                        parent[nx][ny]={x,y};
                        step[nx][ny]=dc[i];
                        q2.push({nx,ny});
                    }
                }
        }
        }
    }
    if(ex==-1){
        cout<<"NO\n";
        return 0;
    }
    string path;
    int x=ex,y=ey;
    while(x!=sx || y!=sy){
        path.push_back(step[x][y]);
        int px=parent[x][y].first;
        int py=parent[x][y].second;
        x=px; y=py;
    }
    reverse(path.begin(),path.end());
    cout<<"YES\n";
    cout<<path.size()<<"\n";
    cout<<path<<"\n";

    



    
}