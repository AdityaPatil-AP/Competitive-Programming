#include<bits/stdc++.h>
using namespace std;

int f(int index, vector<int> &heights, vector<int> &dp, int k){
	if(index == 0){
		return 0;
	}
	if(dp[index] != -1){
		return dp[index];
	}
	int minimum = INT_MAX;
	for(int i = 1;i <= k;i++){
		if(index >= i){
			int way = f(index - i, heights, dp, k) + abs(heights[index] - heights[index - i]);
			minimum = min(minimum, way);
		}
	}
	return dp[index]=minimum;
}

int frogJump(int n, vector<int> &heights, int k)
{
    // Write your code here.
	vector<int> dp (n, -1);
	int ans = f(n - 1, heights, dp,k);
	return ans;
}


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	vector<int> heights(n, 0);
	for(int i = 0;i < n;i++){
		cin >> heights[i];
	}
	int ans = frogJump(n, heights, k);
	cout << ans;
	return 0;
}