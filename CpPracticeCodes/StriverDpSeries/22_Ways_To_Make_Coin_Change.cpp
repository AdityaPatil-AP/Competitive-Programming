#include <bits/stdc++.h>
long long int f(int index, int target, int* denominations, vector<vector<long long int>> &dp){
    if(index == 0){
        return (target % denominations[0] == 0);
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    
    // Explore all the possibilities
    long long int not_take = f(index - 1, target, denominations, dp);
    long long int take = 0;
    if(denominations[index] <= target){
        take = f(index, target - denominations[index], denominations, dp);
    }
    return dp[index][target] = (take + not_take);
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    // Recursion and Memoisation
//     vector<vector<long long int>> dp(n, vector<long long int> (value + 1, -1));
//     return f(n - 1, value, denominations, dp);
    
    // Tabulation Format
    vector<vector<long long int>> dp(n, vector<long long int> (value + 1, 0));
    for(int i = 0;i <= value;i++){
        dp[0][i] = (i % denominations[0] == 0);
    }
    for(int i = 1;i < n;i++){
        for(int target = 0;target <= value;target++){
            long long int not_take = dp[i - 1][target];
            long long int take = 0;
            if(denominations[i] <= target){
                take = dp[i][target - denominations[i]];
            }
            dp[i][target] = (take + not_take);
        }
    }
    return dp[n - 1][value];
    
    // Space Optimisation
    vector<int> curr(value + 1, 0);
    vector<int> prev(value + 1, 0);
    for(int i = 0;i <= value;i++){
        prev[i] = (i % denominations[0] == 0);
    }
    for(int i = 1;i < n;i++){
        for(int target = 0;target <= value;target++){
            long long int not_take = prev[target];
            long long int take = 0;
            if(denominations[i] <= target){
                take = curr[target - denominations[i]];
            }
            curr[target] = (take + not_take);
        }
        prev = curr;
    }
    return prev[value];
}