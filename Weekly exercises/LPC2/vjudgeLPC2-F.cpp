#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin>> n;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin >> h[i];
    }

    int arr=0;
    vector<int> freq(1000001,0);
    for(int i=0; i<n;i++){
        if(freq[h[i]]>0){
            freq[h[i]]--;
        }else{
            arr++;
        }
        freq[h[i]-1]++;
    }
    cout<< arr << "\n";
}