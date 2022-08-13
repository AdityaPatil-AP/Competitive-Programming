int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
//     int totSum = 0;
//     for(int i = 0;i < n;i++){
//         totSum += arr[i];
//     }
//     vector<vector<int>> dp(n, vector<int>(totSum + 1, 0));
//     for(int i = 0;i < n;i++){
//         dp[i][0] = true;
//     }
//     dp[0][arr[0]] = true;
//     for(int i = 1;i < n;i++){
//         for(int target = 1;target <= totSum;target++){
//             bool not_take = dp[i - 1][target];
//             bool take = false;
//             if(arr[i] <= target){
//                 take = dp[i - 1][target - arr[i]];
//             }
//             dp[i][target] = (take | not_take);
//         }
//     }
//     int mini = 1e9;
//     for(int i = 0;i <= (totSum + 1)/2;i++){
//         if(dp[n - 1][i]){
//             int s1 = i;
//             int s2 = totSum - i;
//             mini = min(mini, abs(s1 - s2));
//         }
//     }
//     return mini;
    
    // Space Optimisation
    int totSum = 0;
    for(int i = 0;i < n;i++){
        totSum += arr[i];
    }
    vector<int> prev(totSum + 1, 0);
    vector<int> curr(totSum + 1, 0);
    curr[0] = true;
    prev[0] = true;
    prev[arr[0]] = true;
    for(int i = 1;i < n;i++){
        for(int target = 1;target <= totSum;target++){
            bool not_take = prev[target];
            bool take = false;
            if(arr[i] <= target){
                take = prev[target - arr[i]];
            }
            curr[target] = (take | not_take);
        }
        prev = curr;
    }
    int mini = 1e9;
    for(int i = 0;i <= (totSum + 1)/2;i++){
        if(prev[i]){
            int s1 = i;
            int s2 = totSum - i;
            mini = min(mini, abs(s1 - s2));
        }
    }
    return mini;
}
