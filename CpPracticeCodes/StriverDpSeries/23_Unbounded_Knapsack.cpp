#include <bits/stdc++.h>
int f(int index, int w, vector<int> &weight, vector<int> &profit, vector<vector<int>> &dp){
    if(index == 0){
        return ((w/weight[0]) * profit[0]);
    }
    if(dp[index][w] != -1){
        return dp[index][w];
    }
    // Explore Possibilities
    int not_take = 0 + f(index - 1, w, weight, profit, dp);
    int take = INT_MIN;
    if(weight[index] <= w){
        take = profit[index] + f(index, w - weight[index], weight, profit, dp);
    }
    return dp[index][w] = max(take, not_take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    // Recursion and Memoisation
//     vector<vector<int>> dp(n, vector<int> (w + 1, -1));
//     return f(n - 1, w, weight, profit, dp);
    
    // Tabulation
    vector<vector<int>> dp(n, vector<int> (w + 1, 0));
    for(int i = 0;i <= w;i++){
        dp[0][i] = (i/weight[0]) * profit[0];
    }
    for(int i = 1;i < n;i++){
        for(int wt = 0; wt <= w;wt++){
            int not_take = 0 + dp[i - 1][wt];
            int take = INT_MIN;
            if(weight[i] <= wt){
                take = profit[i] + dp[i][wt - weight[i]];
            }
            dp[i][wt] = max(not_take, take);
        }
    }
    return dp[n - 1][w];
    
    // Space Optimisation - 2 1d arrays
//     vector<int> curr(w + 1, 0), prev(w + 1, 0);
//     for(int i = 0;i <= w;i++){
//         prev[i] = (i/weight[0]) * profit[0];
//     }
//     for(int i = 1;i < n;i++){
//         for(int wt = 0; wt <= w;wt++){
//             int not_take = 0 + prev[wt];
//             int take = INT_MIN;
//             if(weight[i] <= wt){
//                 take = profit[i] + curr[wt - weight[i]];
//             }
//             curr[wt] = max(not_take, take);
//         }
//         prev = curr;
//     }
//     return prev[w];
    
    // Space Optimisation - 1 1d array;
    vector<int> prev(w + 1, 0);
    for(int i = 0;i <= w;i++){
        prev[i] = (i/weight[0]) * profit[0];
    }
    for(int i = 1;i < n;i++){
        for(int wt = 0; wt <= w;wt++){
            int not_take = 0 + prev[wt];
            int take = INT_MIN;
            if(weight[i] <= wt){
                take = profit[i] + prev[wt - weight[i]];
            }
            prev[wt] = max(not_take, take);
        }
    }
    return prev[w];
}
