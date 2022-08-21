#include <bits/stdc++.h>
long f(int ind, int buy, long* values, int n, vector<vector<long>> &dp){
    // Base Case
    if(ind == n){
        return 0;
    }
    if(dp[ind][buy] != -1){
        return dp[ind][buy];
    }
    // Explorations
    long profit;
    if(buy == 1){
        profit = max(-values[ind] + f(ind + 1, 0, values, n, dp),
                     f(ind + 1, 1, values, n, dp));
    }
    else{
        profit = max(values[ind] + f(ind + 1, 1, values, n, dp), 
                     f(ind + 1, 0, values, n, dp));
    }
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    // Best Time to Buy and sell a Stock
//     vector<vector<long>> dp(n, vector<long>(2, -1));
//     return f(0, 1, values, n, dp);
    
    // Tabulation Way
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));
    // Base Case 
    dp[n][0] = 0;
    dp[n][1] = 0;
    for(int i = n - 1;i >= 0;i--){
        dp[i][1] = max(-values[i] + dp[i + 1][0], dp[i + 1][1]);
        dp[i][0] = max(values[i] + dp[i + 1][1], dp[i + 1][0]);
    }
    return dp[0][1];
    
    // Space Optimisation - 
    // Base Case 
    // 2 variable approach 
    long next2 = 0; // if you start on this day and you can sell this stock
    long next1 = 0; // if you start on this day and you can buy this stock
    for(int i = n - 1;i >= 0;i--){
        long curr1 = max(-values[i] + next2, next1);
        long curr2 = max(values[i] + next1, next2);
        next1 = curr1;
        next2 = curr2;
    }
    return next1;
}