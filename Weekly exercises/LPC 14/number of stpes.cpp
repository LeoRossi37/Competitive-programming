#include<bits/stdc++.h>
using namespace std;

#define MAX 1000005

int menor_primo[MAX];
int qtd[MAX];
int freq[MAX];
bool acesa[MAX];

void crivo(){
    for(int i=2; i<MAX; i++){
        if(menor_primo[i]==0){
            menor_primo[i]=i;

            if((long long)i*i<MAX){
                for(long long j=(long long)i*i; j<MAX; j+=i){
                    if(menor_primo[j]==0){
                        menor_primo[j]=i;
                    }
                }
            }
        }
    }
}

vector<int> divisores(int x){
    vector<pair<int,int>> fatores;
    while(x>1){
        int p=menor_primo[x];
        int cont=0;
        while(x%p==0){
            x/=p;
            cont++;
        }
        fatores.push_back({p,cont});
    }
    vector<int> divs;
    divs.push_back(1);
    for(int i=0; i<fatores.size(); i++){
        int p=fatores[i].first;
        int expoente=fatores[i].second;
        int tamanho=divs.size();
        int potencia=1;
        for(int e=1; e<=expoente; e++){
            potencia*=p;

            for(int j=0; j<tamanho; j++){
                divs.push_back(divs[j]*potencia);
            }
        }
    }
    return divs;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    crivo();
    int N;
    cin >> N;
    vector<int> d(N);
    for(int i=0; i<N; i++){
        cin >> d[i];
    }
    freq[0]=MAX-2;
    int maior=0;
    for(int i=0; i<N; i++){
        int x=d[i];
        int valor;
        if(acesa[x]){
            valor=-1;
            acesa[x]=false;
        }else{
            valor=1;
            acesa[x]=true;
        }
        vector<int> divs=divisores(x);
        for(int j=0; j<divs.size(); j++){
            int k=divs[j];
            if(k==1){
                continue;
            }
            freq[qtd[k]]--;
            qtd[k]+=valor;
            freq[qtd[k]]++;
            if(qtd[k]>maior){
                maior=qtd[k];
            }
        }
        while(maior>0 && freq[maior]==0){
            maior--;
        }
        cout << maior << '\n';
    }

    




}