#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int ac;
        cin>>ac;
        vector<pair<int,int>> arr(ac);
        for(int i=0; i<ac; i++){
            cin >> arr[i].first >> arr[i].second;
        }
        sort(arr.begin(),arr.end(),[](auto &a, auto &b){
            return a.second < b.second;
        });
        int count =1;
        int a=arr[0].second;
        for(int i=1;i<ac;i++){
            if(arr[i].first >= a){
                count++;
                a=arr[i].second;
            }
        }
        cout << count << "\n";
    }
    





}