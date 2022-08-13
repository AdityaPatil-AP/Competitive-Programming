int f(int index, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp){
     if(index == 0){
         if(weight[0] <= maxWeight){
             return value[index];
         }
         else{
             return 0;
         }
     }
    if(dp[index][maxWeight] != -1){
        return dp[index][maxWeight];
    }
    
    // Not take the item
    int not_take = 0 + f(index - 1, maxWeight, weight, value, dp);
    int take = INT_MIN;
    if(weight[index] <= maxWeight){
        take = value[index] + f(index - 1, maxWeight - weight[index], weight, value, dp);
    }
    return dp[index][maxWeight] = max(take, not_take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    // Write your code here
    // Recursion and Memoisation
//     vector<vector<int>> dp(n, vector<int> (maxWeight + 1, -1));
//     return f(n - 1, maxWeight, weight, value, dp);
    
    // Tabulation
//     vector<vector<int>> dp(n, vector<int> (maxWeight + 1, 0));
//     if(weight[0] <= maxWeight){
//         for(int i = weight[0];i <= maxWeight;i++){
//             dp[0][i] = value[0];
//         }
//     }
//     for(int i = 1;i < n;i++){
//         for(int wt = 0;wt <= maxWeight;wt++){
//             int not_take = 0 + dp[i - 1][wt];
//             int take = INT_MIN;
//             if(weight[i] <= wt){
//                 take = value[i] + dp[i - 1][wt - weight[i]];
//             }
//             dp[i][wt] = max(take, not_take);
//         }
//     }
//     return dp[n - 1][maxWeight];
    
    // Space Optimisation
//     vector<int> prev(maxWeight + 1, 0), curr(maxWeight + 1, 0);
//     if(weight[0] <= maxWeight){
//         for(int i = weight[0];i <= maxWeight;i++){
//             prev[i] = value[0];
//         }
//     }
//     for(int i = 1;i < n;i++){
//         for(int wt = 0;wt <= maxWeight;wt++){
//             int not_take = 0 + prev[wt];
//             int take = INT_MIN;
//             if(weight[i] <= wt){
//                 take = value[i] + prev[wt - weight[i]];
//             }
//             curr[wt] = max(take, not_take);
//         }
//         prev = curr;
//     }
//     return prev[maxWeight];
    
    // 1 Array Space Optimisation
    vector<int> curr(maxWeight + 1, 0);
    if(weight[0] <= maxWeight){
        for(int i = weight[0];i <= maxWeight;i++){
            curr[i] = value[0];
        }
    }
    for(int i = 1;i < n;i++){
        for(int wt = maxWeight;wt >= 0;wt--){
            int not_take = 0 + curr[wt];
            int take = INT_MIN;
            if(weight[i] <= wt){
                take = value[i] + curr[wt - weight[i]];
            }
            curr[wt] = max(take, not_take);
        }
    }
    return curr[maxWeight];
}