#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
struct No{
    int filho[26];
    bool fim;
    No(){
        for(int i = 0; i < 26; i++){
            filho[i] = -1;
        }

        fim = false;
    }
};

int main(){
    cin.tie(NULL);
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<No> trie(1);
    for(int i = 0; i < k; i++){
        string palavra;
        cin >> palavra;
        int atual = 0;
        for(char c : palavra){
            int x = c - 'a';

            if(trie[atual].filho[x] == -1){
                trie[atual].filho[x] = trie.size();
                trie.push_back(No());
            }
            atual = trie[atual].filho[x];
        }
        trie[atual].fim = true;
    }

    int n = s.size();
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        if(dp[i] == 0){
            continue;
        }
        int atual = 0;
        for(int j = i; j < n; j++){
            int x = s[j] - 'a';
            if(trie[atual].filho[x] == -1){
                break;
            }

            atual = trie[atual].filho[x];
            if(trie[atual].fim){
                dp[j + 1] = (dp[j + 1] + dp[i]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;

    

    
}