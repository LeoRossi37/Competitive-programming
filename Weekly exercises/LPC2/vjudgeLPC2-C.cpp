#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, x;
    cin>> n >> x;
    vector<pair<int,int>> arr(n);
    int a=0, b=n-1;
    for(int i=0;i<n;i++){
        cin >> arr[i].first;
        arr[i].second=i+1;
    }
    sort(arr.begin(),arr.end());
    bool flag=true;
    while(a<b){
        int sum=arr[a].first+arr[b].first;
        if(sum==x){
            cout << arr[b].second << " " << arr[a].second <<"\n";
            flag=false;
            break;
        }
        if(sum<x){
            a++;
        }else{
            b--;
        }
    }

    if(flag)
    cout << "IMPOSSIBLE\n";
    
    
}