int f(int index, int n, vector<int> &price, vector<vector<int>> &dp){
    if(index == 0){
        return n * price[0];
    }
    if(dp[index][n] != -1){
        return dp[index][n];
    }
    // Explorations
    int not_take = 0 + f(index - 1, n, price, dp);
    int take = INT_MIN;
    int rodlength = index + 1;
    if(rodlength <= n){
        take = price[index] + f(index, n - rodlength, price, dp);
    }
    return dp[index][n] = max(take, not_take);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    // It's the same case as unbounded knapsack
    // Recursion and Memoisation
//     vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//     return f(n - 1, n, price, dp);
    
    // Tabulation Way
//     vector<vector<int>> dp(n, vector<int>(n + 1, 0));
//     // Base Case filling
//     for(int i = 0;i <= n;i++){
//         dp[0][i] = i * price[0];
//     }
//     for(int i = 1;i < n;i++){
//         for(int target = 0;target <= n;target++){
//             int not_take = 0 + dp[i - 1][target];
//             int take = INT_MIN;
//             int rod_length = (i + 1);
//             if(rod_length <= target){
//                 take = price[i] + dp[i][target - rod_length];
//             }
//             dp[i][target] = max(take, not_take);
//         }
//     }
//     return dp[n - 1][n];
    
    // Space optimisation - 2 - 1d arrays;
//     vector<int> curr(n + 1, 0), prev(n + 1, 0);
//     // Base Case filling
//     for(int i = 0;i <= n;i++){
//         prev[i] = i * price[0];
//     }
//     for(int i = 1;i < n;i++){
//         for(int target = 0;target <= n;target++){
//             int not_take = 0 + prev[target];
//             int take = INT_MIN;
//             int rod_length = (i + 1);
//             if(rod_length <= target){
//                 take = price[i] + curr[target - rod_length];
//             }
//             curr[target] = max(take, not_take);
//         }
//         prev = curr;
//     }
//     return prev[n];
    
    // Space optimisation - 1 - 1d array
    vector<int> prev(n + 1, 0);
    // Base Case filling
    for(int i = 0;i <= n;i++){
        prev[i] = i * price[0];
    }
    for(int i = 1;i < n;i++){
        for(int target = 0;target <= n;target++){
            int not_take = 0 + prev[target];
            int take = INT_MIN;
            int rod_length = (i + 1);
            if(rod_length <= target){
                take = price[i] + prev[target - rod_length];
            }
            prev[target] = max(take, not_take);
        }
    }
    return prev[n];
    
}

