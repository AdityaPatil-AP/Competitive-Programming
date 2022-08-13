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
    bool not_take = f(index - 1, target, arr, dp);
    bool take = false;
    if(arr[index] <= target){
        take = f(index - 1, target - arr[index], arr, dp);
    }
    return dp[index][target] = (take | not_take);
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
//     int sum = 0;
//     for(int i = 0;i < n;i++){
//         sum += arr[i];
//     }
//     if(sum % 2 != 0){
//         return false;
//     }
//     vector<vector<int>> dp(n, vector<int>(sum/2 + 1, -1));
//     return f(n - 1, sum/2, arr, dp);
    
    // tabulation format
//     int sum = 0;
//     for(int i = 0;i < n;i++){
//         sum += arr[i];
//     }
//     if(sum % 2 != 0){
//         return false;
//     }
//     int target = sum/2;
//     vector<vector<int>> dp(n, vector<int>(target + 1, 0));
//     for(int i = 0;i < n;i++){
//         dp[i][0] = true;
//     }
//     if(arr[0] <= target){
//         dp[0][arr[0]] = true;
//     }
//     for(int i = 1;i < n;i++){
//         for(int j = 1;j <= target;j++){
//             bool not_take = dp[i - 1][j];
//             bool take = false;
//             if(arr[i] <= j){
//                 take = dp[i - 1][j - arr[i]];
//             }
//             dp[i][j] = (take | not_take);
//         }
//     }
//     return dp[n - 1][(sum/2)];
    
    // Space Optimisation
    int sum = 0;
    for(int i = 0;i < n;i++){
        sum += arr[i];
    }
    if(sum % 2 != 0){
        return false;
    }
    int target = sum/2;
    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);
    prev[0] = 1;
    curr[0] = 1;
    if(arr[0] <= target){
        prev[arr[0]] = true;
    }
    for(int i = 1;i < n;i++){
        for(int j = 1;j <= target;j++){
            bool not_take = prev[j];
            bool take = false;
            if(arr[i] <= j){
                take = prev[j - arr[i]];
            }
            curr[j] = (take | not_take);
        }
        prev = curr;
    }
    return prev[(sum/2)];
}
