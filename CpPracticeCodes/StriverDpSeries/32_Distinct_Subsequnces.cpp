class Solution {
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp){
        // if(j < 0)
        //     return 1;
         // In 1-based indexing
        if(j == 0)
            return 1;
        // if(i < 0)
        //     return 0;
        if(i == 0)
            return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        // Explorations
        if(s[i - 1] == t[j - 1]){
            int option1 = f(i - 1, j - 1, s, t, dp);
            int option2 = f(i - 1, j, s, t, dp);
            return dp[i][j] = option1 + option2;
        }
        else{
            return dp[i][j] = f(i - 1, j, s, t, dp);
        }
    }
    
    int numDistinct(string s, string t) {
        // int n = s.size();
        // int m = t.size();
        // // Recursion and Memoisation
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return f(n, m , s, t, dp);
        
        // Tabulation Way
        // int n = s.size();
        // int m = t.size();
        // vector<vector<double>> dp(n + 1, vector<double> (m + 1 , 0));
        // int mod = 1e9 + 7;
        // // Base case;
        // for(int i = 0 ;i <= n;i++) dp[i][0] = 1;
        // for(int i = 1;i <= n;i++){
        //     for(int j = 1;j <= m;j++){
        //         if(s[i - 1] == t[j - 1]){
        //             double option1 = dp[i - 1][j - 1];
        //             double option2 = dp[i - 1][j];
        //             dp[i][j] = (option1 + option2);
        //         }
        //         else{
        //             dp[i][j] = dp[i - 1][j];
        //         }
        //     }
        // }
        // return (int)dp[n][m];
        
        
        // Space Optimised Code - 2 - 1d arrays
//         int n = s.size();
//         int m = t.size();
//         vector<int> curr(m + 1, 0);
//         vector<int> prev(m + 1, 0);
//         prev[0] = 1;
//         int mod = 1e9 + 7;
//         for(int i = 1;i <= n;i++){
//             curr[0] = 1;
//             for(int j = 1;j <= m;j++){
//                 if(s[i - 1] == t[j - 1]){
//                     int option1 = prev[j - 1];
//                     int option2 = prev[j];
//                     curr[j] = (option1 + option2)%mod;
//                 }
//                 else{
//                     curr[j] = prev[j];
//                 }
//             }
//             prev = curr;
//         }
//         return prev[m];
        
        // Space Optimised Code - 1d array
        int n = s.size();
        int m = t.size();
        vector<double> curr(m + 1, 0);
        curr[0] = 1;
        // int mod = 1e9 + 7;
        for(int i = 1;i <= n;i++){
            for(int j = m;j >= 1;j--){
                if(s[i - 1] == t[j - 1]){
                    curr[j] = curr[j - 1] + curr[j];
                }
            }
        }
        return (int)curr[m];
    }
};