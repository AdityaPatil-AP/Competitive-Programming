int mod = 1e9 + 7;

int f(int index, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(index == 0){
        if(target == 0 && arr[0] == 0){
            return 2;
        }
        else if(target == 0 || target == arr[0]){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    
    int not_take = f(index - 1, target, arr, dp);
    int take = 0;
    if(target >= arr[index]){
        take += f(index - 1, target - arr[index], arr, dp);
    }
    return dp[index][target] = (take + not_take)% mod;   
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    // Recursion and Memoization
//     int totSum = 0;
//     for(int i = 0;i < n;i++){
//         totSum += arr[i];
//     }
//     if((totSum - d) % 2 != 0 || (totSum - d) < 0){
//         return 0;
//     }
//     int target = (totSum - d)/2;
//     vector<vector<int>> dp(n, vector<int>(target + 1, -1));
//     return f(n - 1, target, arr, dp);
    
    // Tabulation Format
    int totSum = 0;
    for(int i = 0;i < n;i++){
        totSum += arr[i];
    }
    if((totSum - d) % 2 != 0 || (totSum - d) < 0){
        return 0;
    }
    int target = (totSum - d)/2;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    if(arr[0] == 0){
        dp[0][0] = 2;
    }
    else{
        dp[0][0] = 1;
    }
    if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
    for(int i = 1;i < n;i++){
        for(int j = 0;j <= target;j++){
            int not_take = dp[i - 1][j];
            int take = 0;
            if(j >= arr[i]){
                take = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = (take + not_take)%mod;
        }
    }
    return dp[n - 1][target];
}


