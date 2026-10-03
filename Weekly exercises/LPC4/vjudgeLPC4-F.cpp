#include <bits/stdc++.h>
using namespace std;

int n;
bool board[10][10];
bool vis[10][10];

int dr[8] = {-2,-2,-1,-1,1,1,2,2};
int dc[8] = {-1,1,-2,2,-2,2,-1,1};

int total, best;

void dfs(int r, int c, int count){
    vis[r][c] = true;
    best = max(best, count);
    for(int i=0; i<8; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr>=0 && nr<10 && nc>=0 && nc<10){
            if(board[nr][nc] && !vis[nr][nc]){
                dfs(nr, nc, count+1);
            }
        }
    }

    vis[r][c] = false; 



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int caseNum = 1;

    while(cin >> n && n){
        memset(board, false, sizeof(board));
        memset(vis, false, sizeof(vis));
        total = 0;
        for(int i=0; i<n; i++){
            int offset, cnt;
            cin >> offset >> cnt;
            for(int j=0; j<cnt; j++){
                board[i][offset + j] = true;
                total++;
            }
        }
        best = 0;
        dfs(0, 0, 1);
        int unreachable = total - best;
        cout << "Case " << caseNum++ << ", ";
        if(unreachable == 1)
            cout << "1 square can not be reached.\n";
        else
            cout << unreachable << " squares can not be reached.\n";
    }

    



}