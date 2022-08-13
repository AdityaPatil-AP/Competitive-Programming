int f(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp){
    if(i == n){
        return triangle[i][j];
    }
    if(dp[i][j] != (-(1e9 + 1))){
        return dp[i][j];
    }
    int down = triangle[i][j] + f(i + 1,j, triangle, n, dp);
    int ddiag = triangle[i][j] + f(i + 1, j + 1, triangle, n, dp);
    return dp[i][j] = min(down, ddiag);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    // Recursion then after that due to overlapping sub-problems
    // We used Memoisation
//     vector<vector<int>> dp(n, vector<int>(n, -1e9 - 1));
//     return f(0, 0, triangle, n - 1, dp);
    
//     // Memoisation - to reduce the recursion stack space
//     vector<vector<int>> dp(n, vector<int> (n, 0));
//     // Declare the base case
//     for(int i = 0;i < n;i++){
//         dp[n - 1][i] = triangle[n - 1][i];
//     }
//     // As tabulation is bottom- up approach we start it by filling the base 
//     // case first and then we fill up the whole grid;
//     for(int i = n - 2;i >= 0;i--){
//         for(int j = i;j >= 0;j--){
//             int down = triangle[i][j] + dp[i + 1][j];
//             int ddiag = triangle[i][j] + dp[i + 1][j + 1];
//             dp[i][j] = min(down, ddiag);
//         }
//     }
//     return dp[0][0];
    
    // Space optimisation - to reduce the 2-d vector usage to just 2 
    // 1 - d vectors
    vector<int> front(n, 0);
    for(int i = 0;i < n;i++){
        front[i] = triangle[n - 1][i];
    }
    for(int i = n - 2;i>= 0;i--){
        vector<int> curr(n, 0);
        for(int j = i;j >= 0;j--){
            int down = triangle[i][j] + front[j];
            int ddiag = triangle[i][j] + front[j + 1];
            curr[j] = min(down, ddiag);
        }
        front = curr;
    }
    return front[0];
}