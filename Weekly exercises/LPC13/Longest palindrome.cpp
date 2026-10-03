#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> d1(n);
    int l = 0, r = -1;
    for(int i = 0; i < n; i++){
        int k;
        if(i > r){
            k = 1;
        }else{
            k = min(d1[l + r - i], r - i + 1);
        }
        while(i - k >= 0 && i + k < n && s[i - k] == s[i + k]){
            k++;
        }
        d1[i] = k--;

        if(i + k > r){
            l = i - k;
            r = i + k;
        }
    }
    vector<int> d2(n);
    l = 0;
    r = -1;
    for(int i = 0; i < n; i++){
        int k;
        if(i > r){
            k = 0;
        }else{
            k = min(d2[l + r - i + 1], r - i + 1);
        }
        while(i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]){
            k++;
        }
        d2[i] = k--;
        if(i + k > r){
            l = i - k - 1;
            r = i + k;
        }
    }
    int melhorInicio = 0;
    int melhorTamanho = 1;

    for(int i = 0; i < n; i++){
        int tamanho = 2 * d1[i] - 1;
        if(tamanho > melhorTamanho){
            melhorTamanho = tamanho;
            melhorInicio = i - d1[i] + 1;
        }
        tamanho = 2 * d2[i];
        if(tamanho > melhorTamanho){
            melhorTamanho = tamanho;
            melhorInicio = i - d2[i];
        }
    }

    
    cout << s.substr(melhorInicio, melhorTamanho) << endl;

    


}