#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n;i++){
        int num;
        string bin;
        cin >> num; 
        bin=bitset<32>(num).to_string();
        bin.erase(0, bin.find('1'));
        reverse(bin.begin(),bin.end());
        bin.erase(0, bin.find('1'));
        int dec= stoi(bin,nullptr,2);
        cout << dec << endl;
    }
}  