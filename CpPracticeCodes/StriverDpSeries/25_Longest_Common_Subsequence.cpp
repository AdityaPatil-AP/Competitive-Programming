#include<bits/stdc++.h>
// Without shifting of Index
// int f(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp){
//     // Base Case
//     if(ind1 < 0 || ind2 < 0){
//         return 0;
//     }
//     if(dp[ind1][ind2] != -1){
//         return dp[ind1][ind2];
//     }
//     // Explorations
//     if(s[ind1] == t[ind2]){
//         return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, s, t, dp);
//     }
//     else{
//         return dp[ind1][ind2] = 0 + max(f(ind1 - 1, ind2, s, t, dp), f(ind1, ind2 - 1, s, t, dp));
//     }
// }

// With Shifting of Index
int f(int ind1, int ind2, string &s, string &t, vector<vector<int>> &dp){
    // Base Case
    if(ind1 == 0 || ind2 == 0){
        return 0;
    }
    if(dp[ind1][ind2] != -1){
        return dp[ind1][ind2];
    }
    // Explorations
    if(s[ind1 - 1] == t[ind2 - 1]){
        return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, s, t, dp);
    }
    else{
        return dp[ind1][ind2] = 0 + max(f(ind1 - 1, ind2, s, t, dp), f(ind1, ind2 - 1, s, t, dp));
    }
}

int lcs(string s, string t)
{
    //Write your code here
    // Recursion and Memoisation
//     int n = s.size();
//     int m = t.size();
//     vector<vector<int>> dp(n, vector<int> (m, -1));
//     return f(n - 1, m - 1, s, t, dp);
    
    // With shifting of Index
//     int n = s.size();
//     int m = t.size();
//     vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
//     return f(n , m , s, t, dp);  
    
    // Tabulation - Without shifting
//     int n = s.size();
//     int m = t.size();
//     vector<vector<int>> dp(n, vector<int> (m, 0));
//     for(int i = 0;i < n;i++){
//         for(int j = 0;j < m;j++){
//             if(s[i] == t[j]){
//                 dp[i][j] = 1;
//                 if(i > 0 && j > 0){
//                     dp[i][j] += dp[i - 1][j - 1];
//                 }
//             }
//             else{
//                 int p1 = 0, p2 = 0;
//                 if(i > 0)
//                     p1 += dp[i - 1][j];
//                 if(j > 0){
//                     p2 += dp[i][j - 1];
//                 }
//                 dp[i][j] = max(p1, p2);
//             }
//         }
//     }
//     return dp[n - 1][m - 1];
    
    // Tabulation - With shifting
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            // Matching
            if(s[i - 1] == t[j - 1]){
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
    return dp[n][m];
    
    // Space Optimisation - 2 - 1d array optimisation
//     int n = s.size();
//     int m = t.size();
//     vector<int> prev(m, 0), curr(m, 0);
//     for(int i = 0;i < n;i++){
//         for(int j = 0;j < m;j++){
//             if(s[i] == t[j]){
//                 curr[j] = 1;
//                 if(i > 0 && j > 0){
//                     curr[j] += prev[j - 1];
//                 }
//             }
//             else{
//                 int p1 = 0, p2 = 0;
//                 if(i > 0)
//                     p1 += prev[j];
//                 if(j > 0){
//                     p2 += curr[j - 1];
//                 }
//                 curr[j] = max(p1, p2);
//             }
//         }
//         prev = curr;
//     }
//     return prev[m - 1];
    
    
}