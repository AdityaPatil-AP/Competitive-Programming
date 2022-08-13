long long int f(int index, int target, vector<int> &arr, vector<vector<long long int>> &dp){
    // Base Case
    if(index == 0){
        if(target % arr[0] == 0) return (target/arr[0]);
        else return 1e10;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }    
    // Explore the possibilities
    long long int not_take = 0 + f(index - 1, target, arr, dp);
    long long int take = 1e10;
    if(arr[index] <= target){
        take = 1 + f(index, target - arr[index], arr, dp);
    }
    return dp[index][target] = min(take, not_take);
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    // Recursion
    // and them Memoisation
//     int n = num.size();
//     vector<vector<long long int>> dp(n, vector<long long int> (x + 1, -1));
//     long long int ans = f(n - 1, x, num, dp);
//     if(ans >= 1e10){
//         return -1;
//     }
//     else{
//         return ans;
//     }
    
    // Tabulation 
//     int n = num.size();
//     vector<vector<long long int>> dp(n, vector<long long int> (x + 1, 0));
//     for(int i = 0;i <= x;i++){
//         if(i % num[0] == 0){
//             dp[0][i] = i / num[0];
//         }    
//         else{
//             dp[0][i] = 1e10;
//         }
//     }
//     for(int i = 1;i < n;i++){
//         for(int j = 0;j <= x;j++){
//             long long int not_take = 0 + dp[i - 1][j];
//             long long int take = 1e10;
//             if(num[i] <= j){
//                 take = 1 + dp[i][j - num[i]];
//             }
//             dp[i][j] = min(take, not_take);
//         }
//     }
//     if(dp[n - 1][x] >= 1e10){
//         return -1;
//     }
//     else{
//         return dp[n - 1][x];
//     }
    
    // Space Optimisation
    int n = num.size();
    vector<long long int> curr(x + 1, 0);
    vector<long long int> prev(x + 1, 0);
    for(int i = 0;i <= x;i++){
        if(i % num[0] == 0){
            prev[i] = i / num[0];
        }    
        else{
            prev[i] = 1e10;
        }
    }
    for(int i = 1;i < n;i++){
        for(int j = 0;j <= x;j++){
            long long int not_take = 0 + prev[j];
            long long int take = 1e10;
            if(num[i] <= j){
                take = 1 + curr[j - num[i]];
            }
            curr[j] = min(take, not_take);
        }
        prev = curr;
    }
    if(prev[x] >= 1e10){
        return -1;
    }
    else{
        return prev[x];
    }
}