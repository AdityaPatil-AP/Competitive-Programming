#include<bits/stdc++.h>
using namespace std;

int sum(int n){
	if(n == 0){
		return 0;	
	}
	return n + sum(n - 1);
}

void fact(int n, int &ans){
	if(n == 0){
		return;
	}
	ans = ans * n;
	fact(n - 1, ans);
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n = 5;
	cin >> n;
	int ans = sum(n);
	cout << ans << endl;
	ans = 1;
	fact(n, ans);
	cout << ans << endl;
	return 0;
}