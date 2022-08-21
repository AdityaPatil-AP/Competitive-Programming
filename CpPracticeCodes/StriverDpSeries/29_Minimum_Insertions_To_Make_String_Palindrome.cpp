#include <vector>
int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    int n = s.size();
    string s2 = string(s.rbegin(), s.rend());
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            // Matching
            if(s[i - 1] == s2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            // Not Matching
            else{
                int p1 = 0, p2 = 0;
                p1 += dp[i - 1][j];
                p2 += dp[i][j - 1];
                dp[i][j] = max(p1, p2);
            }
        }
    }
    return dp[n][n];
}
int minCharsforPalindrome(string str){
	// Write your code here
    return str.size() - longestPalindromeSubsequence(str);
}