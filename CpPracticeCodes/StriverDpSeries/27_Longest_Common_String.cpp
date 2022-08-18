int lcs(string &s, string &t){
	//	Write your code here.
//     int n = s.size();
//     int m = t.size();
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//     for(int i = 0;i <= n;i++) dp[i][0] = 0;
//     for(int j = 0;j <= m;j++) dp[0][j] = 0;
//     int maxi = 0;
//     for(int i = 1;i <= n;i++){
//         for(int j = 1;j <= m;j++){
//             if(s[i - 1] == t[j - 1]){
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//                 maxi = max(maxi, dp[i][j]);
//             }
//             else{
//                 dp[i][j] = 0;
//             }
//         }
//     }
//     return maxi;
    
    // Space Optimisation
     int n = s.size();
    int m = t.size();
    vector<int> curr(m + 1, 0);
    vector<int> prev(m + 1, 0);
    for(int i = 0;i <= m;i++) prev[i] = 0;
    curr[0] = 0;
    int maxi = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(s[i - 1] == t[j - 1]){
                curr[j] = 1 + prev[j - 1];
                maxi = max(maxi, curr[j]);
            }
            else{
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return maxi;
}