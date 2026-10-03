#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, x;
	cin >> n >> x;
	queue<int> q;
	long long sum=0;
	int count=0;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		q.push(a);
		sum+=a;
		while(sum>x && !q.empty()){
			sum-=q.front();
			q.pop();
		}
		if(sum==x){
			count++;
		}
	}

	cout << count << "\n";





}