#define mod 1000000007

int f(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(n == 0 && m == 0){
        return (mat[n][m] != -1) ? 1 : 0;
    }
    if(n < 0 || m < 0){
        return 0;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    // One edge case i was missing
    if(mat[n][m] == -1){
        return 0;
    }
    int up = 0, down = 0;
    if(n > 0 && mat[n - 1][m] != -1){
        up = f(n - 1, m, mat, dp)%mod;
    }
    if(m > 0 && mat[n][m - 1] != -1){
        down = f(n, m - 1, mat, dp)%mod;
    }
    return dp[n][m] = (up + down)%mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    // Recursion + Memoization
//     vector<vector<int>> dp(n, vector<int> (m, -1));
//     return f(n - 1, m - 1, mat, dp);
    
    // Tabulation Format
//     if(mat[0][0] == -1){
//         return 0;
//     }
//     else{
//         vector<vector<int>> dp(n, vector<int>(m, 0));
//         dp[0][0] = 1;
//         for(int i = 0;i < n;i++){
//             for(int j = 0;j < m;j++){
//                 if(i == 0 && j == 0) continue;
//                 int up = 0, left = 0;
//                 if(mat[i][j] == -1){
//                     dp[i][j] = 0;
//                     continue;
//                 }
//                 if(i > 0 && mat[i - 1][j] != -1){
//                     up = dp[i - 1][j];
//                 }
//                 if(j > 0 && mat[i][j - 1] != -1){
//                     left = dp[i][j - 1];
//                 }
//                 dp[i][j] = (up + left)%mod;
//             }
//         }
//         return dp[n - 1][m - 1];
//     }
    
    // Space Optimisation
    if(mat[0][0] == -1){
        return 0;
    }
    else{
        vector<int> prev(m, 0);
        for(int i = 0;i < n;i++){
            vector<int> curr(m, 0);
            for(int j = 0;j < m;j++){
                if(i == 0 && j == 0) { curr[0] = 1; continue;}
                int up = 0, left = 0;
                if(mat[i][j] == -1){
                    curr[j] = 0;
                    continue;
                }
                if(i > 0 && mat[i - 1][j] != -1){
                    up = prev[j];
                }
                if(j > 0 && mat[i][j - 1] != -1){
                    left = curr[j - 1];
                }
                curr[j] = (up + left)%mod;
            }
            prev = curr;
        }
        return prev[m - 1];
    }
}