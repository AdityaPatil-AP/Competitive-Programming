int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int n = str.size();
    int m = ptr.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            // Matching
            if(str[i - 1] == ptr[j - 1]){
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
    return (str.size() + ptr.size() - 2 * (dp[n][m]));
}