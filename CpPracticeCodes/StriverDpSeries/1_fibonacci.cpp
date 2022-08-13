#include<bits/stdc++.h>
using namespace std;

int f(int n, vector<int> &dp){
	if(n <= 1){
		return n;
	}
	if(dp[n] > -1){
		return dp[n];
	}
	dp[n] = f(n - 1, dp) + f(n - 2, dp);
	return dp[n];
}

int main(){
	// #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	// #endif
	// Recursive + Memoization Technique
	int n;
	cin >> n;
	vector<int> dp(n + 1, -1);
	cout << f(n, dp) << endl;
	// Tabulation Format Way
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2;i <= n;i++){
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << endl;
	// Optimised Space Technique
	int prev = 1, prev2 = 0;
	int curri;
	for(int i = 2;i <= n;i++){
		curri = prev + prev2; 
		prev2 = prev;
		prev = curri;
	}
	cout << curri << endl;
}