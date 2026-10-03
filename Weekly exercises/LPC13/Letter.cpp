#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int freq[256] = {};
    for(char c : s1){
        if(c != ' '){
            freq[c]++;
        }
    }
    bool pode = true;
    for(char c : s2){
        if(c != ' '){
            freq[c]--;

            if(freq[c] < 0){
                pode = false;
            }
        }
    }

    if(pode){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    




}