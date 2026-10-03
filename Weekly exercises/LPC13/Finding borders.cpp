#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pi(n);
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    vector<int> resposta;
    int j = pi[n - 1];
    while(j > 0){
        resposta.push_back(j);
        j = pi[j - 1];
    }
    reverse(resposta.begin(), resposta.end());
    for(int i = 0; i < resposta.size(); i++){
        if(i > 0){
            cout << " ";
        }
        cout << resposta[i];
    }
    cout << "\n";

    

}