#include <bits/stdc++.h>
using namespace std;

bool col[16], diag1[16], diag2[16],reservado[8][8];
long long x;

void backtracking(long long i){
    if(i==8){
        x++;
        return;
    }
    for(int j=0; j<8;j++){
        if(col[j] || diag1[i+j] || diag2[i-j+7]|| reservado[i][j]){
            continue;
        }else{
            col[j]=diag1[i+j]=diag2[i-j+7]=true;
            backtracking(i+1);
            col[j]=diag1[i+j]=diag2[i-j+7]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0; i<16; i++){
        col[i]=diag1[i]=diag2[i]=false;
    }
    string a;
    for(int i=0;i<8;i++){
        cin >> a;
        for(int j=0; j<8; j++){
            reservado[i][j]=a[j]!='.';
        }
    }
    backtracking(0);
    cout << x << "\n";


}