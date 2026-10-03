#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string frase;
    getline(cin, frase);
    int qtd = 0;
    bool dentro = false;

    for(char c : frase){
        if(isalnum(c)){
            if(!dentro){
                qtd++;
                dentro = true;
            }
        }else{
            dentro = false;
        }
    }
    cout << qtd << endl;




}