bool f(int index, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0){
        return true;
    }
    if(index == 0){
        return (arr[0] == target);
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    // Exploring the possibilities
    bool not_take = f(index - 1, target, arr, dp);
    bool take = false;
    if(target >= arr[index]){
        take = f(index - 1, target - arr[index], arr, dp);
    }
    
    return dp[index][target] = (take || not_take);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    // Recursion 
    // Memoization :
//     vector<vector<int>> dp(n, vector<int>(k + 1, -1));
//     return f(n - 1, k, arr, dp);
    
    // Tabulation Format
    // Base Cases
//     vector<vector<int>> dp(n, vector<int>(k + 1, 0));
//     for(int i = 0; i < n;i++){
//         dp[i][0] = true;
//     }
//     if(arr[0] <= k){
//         dp[0][arr[0]] = true;
//     }
//     for(int i = 1;i < n;i++){
//         for(int j = 1;j <= k;j++){
//             bool not_take = dp[i - 1][j];
//             bool take = false;
//             if(j >= arr[i]){
//                 take = dp[i - 1][j - arr[i]];
//             }
//             dp[i][j] = (take || not_take);
//         }
//     }
//     return dp[n - 1][k];
    
    // Space Optimisation
    
    vector<int> prev(k+1, 0);
    prev[0] = 1;
    if(arr[0] <= k){
        prev[arr[0]] = true;
    }
    for(int i = 1;i < n;i++){
        vector<int> curr(k + 1, 0);
        curr[0] = 1;
        for(int j = 1;j <= k;j++){
            bool not_take = prev[j];
            bool take = false;
            if(j >= arr[i]){
                take = prev[j - arr[i]];
            }
            curr[j] = (take || not_take);
        }
        prev = curr;
    }
    return prev[k];
}