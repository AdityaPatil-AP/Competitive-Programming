#include<bits/stdc++.h>
using namespace std;

int main(){
	// #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	// #endif
	// Visualisation done in the copy
	string s = "abcde";
	string t = "bdgek";
	int n = s.size();
	int m = t.size();

	// To find and print the lcs of two strings 
	
	// Find lcs
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for(int i = 0;i <= n;i++) dp[i][0] = 0;
	for(int j = 0;j <= m;j++) dp[0][j] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(s[i - 1] == t[j - 1]){
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else{
				int p1 = dp[i - 1][j];
				int p2 = dp[i][j - 1];
				dp[i][j] = max(p1, p2);
			}
		}
	}
	cout << dp[n][m] << endl;
	// Time Complexity - o(m + n)
	// Found the lcs and analyse the dp array
	int lcs = dp[n][m];	
	string ans = "";
	int i = n, j =m;
	while(i > 0 && j > 0){
		if(s[i - 1] == t[j - 1]){
			ans = s[i - 1] + ans;
			i = i - 1;
			j = j - 1;
		}
		else if(dp[i][j - 1] > dp[i - 1][j]){
			j = j - 1;
		}
		else{
			i = i - 1;
		}
	}
	cout << ans << endl;
}