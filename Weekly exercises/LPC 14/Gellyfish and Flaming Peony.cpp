#include<bits/stdc++.h>
using namespace std;

#define MAX 5005
#define INF 1000000000

int mdc(int a, int b){
    while(b!=0){
        int aux=b;
        b=a%b;
        a=aux;
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int g=0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            g=mdc(g,a[i]);
        }
        int qtd=0;
        for(int i=0; i<n; i++){
            if(a[i]==g){
                qtd++;
            }
        }
        if(qtd>0){
            cout << n-qtd << '\n';
            continue;
        }
        vector<int> dp(MAX,INF);
        for(int i=0; i<n; i++){
            vector<int> novo=dp;
            novo[a[i]]=1;
            for(int j=1; j<MAX; j++){
                if(dp[j]!=INF){
                    int x=mdc(j,a[i]);
                    novo[x]=min(novo[x],dp[j]+1);
                }
            }

            dp=novo;
        }
        int tam=dp[g];
        cout << n+tam-2 << '\n';
    }

    



    
}