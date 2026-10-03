#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, A, B;
    cin >> N >> A >> B;
    vector<double> dp(N+1, 0);
    vector<double> prefixo(N+1, 0);
    int qtd = B-A+1;
    for(int i=1; i<=N; i++){
        if(A == 0){
            int inicio = max(1, i-B);
            int fim = i-1;
            double soma = 0;
            if(inicio <= fim){
                soma = prefixo[fim] - prefixo[inicio-1];
            }
            dp[i] = ((double)qtd + soma) / B;
        }else{
            int inicio = max(1, i-B);
            int fim = i-A;
            double soma = 0;
            if(inicio <= fim){
                soma = prefixo[fim] - prefixo[inicio-1];
            }
            dp[i] = 1.0 + soma/qtd;
        }
        prefixo[i] = prefixo[i-1] + dp[i];
    }

    cout << fixed << setprecision(10);
    cout << dp[N] << "\n";

    




}