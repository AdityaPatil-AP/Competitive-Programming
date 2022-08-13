
int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(j < 0 || j >= matrix[0].size()){
        return -(1e6 + 1);
    }
    if(i == 0){
        return matrix[0][j];
    }
    if(dp[i][j] != -1e9){
        return dp[i][j];
    }
    // Three moves up, upld, uprd
    int up = matrix[i][j] + f(i - 1,j, matrix, dp);
    int upld = matrix[i][j] + f(i - 1, j - 1, matrix, dp);
    int uprd = matrix[i][j] + f(i - 1, j + 1, matrix, dp);
    
    return dp[i][j] = max(up, max(upld, uprd));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    // Recursion
//     int n = matrix.size();
//     int m = matrix[0].size();
//     int maxi = -1e9;
    // Memoisation - overlapping sub-problems
//     Use dp array
//     vector<vector<int>> dp(n, vector<int> (m, -1e9));
//     for(int i = 0;i < m;i++){
//         maxi = max(maxi, f(n - 1, i, matrix, dp));
//     }
//     return maxi;
    
    // Tabulation Format- To remove recursion stack space
//     int n = matrix.size();
//     int m = matrix[0].size();
//     vector<vector<int>> dp(n, vector<int> (m, 0));
//     // Base Case
//     for(int i = 0;i < m;i++){
//         dp[0][i] = matrix[0][i];
//     }
//     for(int i = 1;i < n;i++){
//         for(int j = 0;j < m;j++){
//             int up = matrix[i][j] + dp[i - 1][j];
//             int upld = matrix[i][j], uprd = matrix[i][j];
//             if((j - 1) >= 0)
//                 upld += dp[i - 1][j - 1];
//             else 
//                 upld += (-1e7);
//             if((j + 1) < m)
//                 uprd += dp[i - 1][j + 1];
//             else
//                 uprd += (-1e7);
//             dp[i][j] = max(up, max(upld, uprd));
//         }
//     }
//     int maxi = -1e9;
//     for(int j = 0;j < m;j++){
//         maxi = max(maxi, dp[n - 1][j]);
//     }
//     return maxi;
    
    // Space optimization - to reduce the space complexity
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m, 0);
    // Base Case
    for(int i = 0;i < m;i++){
        prev[i] = matrix[0][i];
    }
    for(int i = 1;i < n;i++){
        vector<int> curr(m, 0);
        for(int j = 0;j < m;j++){
            int up = matrix[i][j] + prev[j];
            int upld = matrix[i][j], uprd = matrix[i][j];
            if((j - 1) >= 0)
                upld += prev[j - 1];
            else 
                upld += (-1e7);
            if((j + 1) < m)
                uprd += prev[j + 1];
            else
                uprd += (-1e7);
            curr[j] = max(up, max(upld, uprd));
        }
        prev = curr;
    }
    int maxi = -1e9;
    for(int j = 0;j < m;j++){
        maxi = max(maxi, prev[j]);
    }
    return maxi;
}