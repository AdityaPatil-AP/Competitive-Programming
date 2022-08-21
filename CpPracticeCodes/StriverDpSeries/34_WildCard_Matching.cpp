#include <vector>
bool f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp){
    // Base Case
    if(i < 0 && j < 0){
        return true;
    }
    if(i < 0 && j >= 0){
        return false;
    }
    if(j < 0 && i >= 0){
        for(int i1 = 0;i1 <= i;i1++){
            if(pattern[i1] != '*'){
                return false;
            }
        }
        return true;
    }    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    // Explorations
    if(pattern[i] == text[j] || pattern[i] == '?'){
        return dp[i][j] = f(i - 1, j - 1, pattern, text, dp);
    }
    if(pattern[i] == '*'){
        return dp[i][j] = (f(i - 1, j, pattern, text,dp) | f(i, j - 1, pattern, text, dp));
    }
    else{
        return dp[i][j] = false;
    }
}

bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
//     int n = pattern.size();
//     int m = text.size();
//     // Recursion and Memoisation
//     vector<vector<int>> dp(n, vector<int>(m, -1));
//     return f(n - 1, m - 1, pattern, text, dp);
    
    // Tabulation - To remove the recursion stack space.
//     int n = pattern.size();
//     int m = text.size();
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//     dp[0][0] = 1;
//     for(int i = 1;i <= m;i++) dp[0][i] = 0;
//     int cnt = 0;
//     for(int i = 1;i <= n;i++){
//         if(pattern[i - 1] == '*'){
//             cnt++;
//         }
//         else{
//             break;
//         }
//     }
//     for(int i = 1;i <= cnt;i++) dp[i][0] = 1;
//     for(int i = 1;i <= n;i++){
//         bool flag = true;
//         for(int ii = 1;ii <= i;ii++){
//             if(pattern[ii - 1] != '*'){
//                 flag = false;
//                 break;
//             }
//         }
//         dp[i][0] = flag;
//     }
//     for(int i = 1;i <= n;i++){
//         for(int j = 1; j <= m;j++){
//             if(pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?'){
//                 dp[i][j] = dp[i - 1][j - 1];
//             }
//             else if(pattern[i - 1] == '*'){
//                 dp[i][j] = (dp[i][j - 1] | dp[i - 1][j]);
//             }
//             else{
//                 dp[i][j] = 0;
//             }
//         }
//     }
//     return (bool)dp[n][m];
    
    // Space Optimisation - 2 1d arrays;
    int n = pattern.size();
    int m = text.size();
    vector<int> curr(m + 1,0), prev(m + 1, 0);
    prev[0] = 1;
    for(int i = 1;i <= m;i++) prev[i] = 0;
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(pattern[i - 1] == '*'){
            cnt++;
        }
        else{
            break;
        }
    }
    for(int i = 1;i <= n;i++){
        if(i <= cnt)
            curr[0] = 1;
        for(int j = 1; j <= m;j++){
            if(pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?'){
                curr[j] = prev[j - 1];
            }
            else if(pattern[i - 1] == '*'){
                curr[j] = (curr[j - 1] | prev[j]);
            }
            else{
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return (bool)prev[m];
}
