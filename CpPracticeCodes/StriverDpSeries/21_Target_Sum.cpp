int f(int index, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(index == 0){
        if(target == 0 && target == arr[0]){
            return 2;
        }
        else if(target == 0 || target == arr[0]){
            return 1;
        }
        else return 0;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    
    // Explorations
    int not_take = f(index - 1, target, arr, dp);
    int take = 0;
    if(arr[index] <= target){
        take = f(index - 1, target - arr[index], arr, dp);
    }
    
    return dp[index][target] = (take + not_take);
}

int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    // Recursion and Memoisation
//     int totSum = 0;
//     for(int &it:arr){
//         totSum += it;
//     }
//     int k = (target + totSum)/2;
//     if((target + totSum)%2 != 0 || k > totSum){
//         return 0;
//     }
//     vector<vector<int>> dp(n, vector<int> (k + 1, -1));
//     return f(n - 1, k, arr, dp);
    
    // Tabulation
    int totSum = 0;
    for(int &it:arr){
        totSum += it;
    }
    int k = (target + totSum)/2;
    if((target + totSum)%2 != 0 || k > totSum){
        return 0;
    }
    vector<vector<int>> dp(n, vector<int> (k + 1, 0));
   // Base Case;
    dp[0][0] = 1;
    if(arr[0] == 0) dp[0][0] = 2;
    else if(arr[0] <= k) dp[0][arr[0]] = 1;
    
    for(int i = 1;i < n;i++){
        for(int target = 0;target <= k;target++){
            int not_take = dp[i - 1][target];
            int take = 0;
            if(arr[i] <= target){
                take = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = (take + not_take);
        }
    }
    return dp[n - 1][k];
}
