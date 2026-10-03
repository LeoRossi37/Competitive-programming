#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> menor(MAX, 1000000000);
    vector<int> segundo_menor(MAX, 1000000000);
    vector<int> qtd(MAX, 0);

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        int aux=x;
        for(int p=2; p*p<=aux; p++){
            if(aux%p==0){
                int expoente=0;
                while(aux%p==0){
                    aux/=p;
                    expoente++;
                }
                qtd[p]++;
                if(expoente<menor[p]){
                    segundo_menor[p]=menor[p];
                    menor[p]=expoente;
                }else if(expoente<segundo_menor[p]){
                    segundo_menor[p]=expoente;
                }
            }
        }
        if(aux>1){
            qtd[aux]++;
            int expoente=1;
            if(expoente<menor[aux]){
                segundo_menor[aux]=menor[aux];
                menor[aux]=expoente;
            }else if(expoente<segundo_menor[aux]){
                segundo_menor[aux]=expoente;
            }
        }
    }
    
    long long resposta=1;
    for(int p=2; p<MAX; p++){
        int expoente=0;
        if(qtd[p]==n){
            expoente=segundo_menor[p];
        }else if(qtd[p]==n-1){
            expoente=menor[p];
        }
        for(int i=0; i<expoente; i++){
            resposta*=p;
        }
    }

    cout << resposta << '\n';

    




}