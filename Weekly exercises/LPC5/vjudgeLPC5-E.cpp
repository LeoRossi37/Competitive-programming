#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int>> right;
        int x; 
        while(true){
            cin >> x;
            if(x == 0) break;
            if(x == -1){
                cout << left.top() << "\n";
                left.pop();
                if(right.size() > left.size()){
                    left.push(right.top());
                    right.pop();
                }
            }
            else{
                if(left.empty() || x <= left.top())
                    left.push(x);
                else
                    right.push(x);

                if(left.size() > right.size() + 1){
                    right.push(left.top());
                    left.pop();
                }
                else if(right.size() > left.size()){
                    left.push(right.top());
                    right.pop();
                }
            }
        }
    }







}