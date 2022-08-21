int f(int ind, int transNo, vector<int> &prices, int n, int k, vector<vector<int>> &dp){
    // Base Case
    if(ind == n || transNo == (2 * k)){
         return 0;   
    }
    if(dp[ind][transNo] != -1){
        return dp[ind][transNo];
    }
    // Explorations
    if(transNo % 2 == 0){
        return dp[ind][transNo] = max(-prices[ind] + f(ind + 1, transNo + 1, prices, n, k, dp),
                  f(ind + 1, transNo, prices, n, k, dp));
    }
    else{
        return dp[ind][transNo] = max(prices[ind] + f(ind + 1, transNo + 1, prices, n, k, dp),
                  f(ind + 1, transNo, prices, n, k, dp));
    }
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    // Another method - Recursion and then Memoization
//     vector<vector<int>> dp(n, vector<int> (2 * k, -1));
//     return f(0, 0, prices, n, k, dp);
    
    // Tabulation Answer
//     vector<vector<int>> dp(n + 1, vector<int> (2 * k + 1, 0));
//     // Base case is returning 0 so no need to intialize it. 
//     for(int i = n - 1;i >= 0;i--){
//         for(int tn = 2*k - 1;tn >= 0;tn--){
//             if(tn % 2 == 0){
//                 dp[i][tn] = max(-prices[i] + dp[i + 1][tn + 1],
//                                dp[i + 1][tn]);
//             }
//             else{
//                 dp[i][tn] = max(prices[i] + dp[i + 1][tn + 1],
//                                dp[i + 1][tn]);
//             }
//         }
//     }
//     return dp[0][0];
    
    // Space Optimisation
    vector<int> ahead(2 * k + 1, 0);
    vector<int> curr(2 * k + 1, 0);
    // Base case is returning 0 so no need to intialize it. 
    for(int i = n - 1;i >= 0;i--){
        for(int tn = 2*k - 1;tn >= 0;tn--){
            if(tn % 2 == 0){
                curr[tn] = max(-prices[i] + ahead[tn + 1],
                               ahead[tn]);
            }
            else{
                curr[tn] = max(prices[i] + ahead[tn + 1],
                               ahead[tn]);
            }
        }
        ahead = curr;
    }
    return ahead[0];
    
    // Using stock 3 tabulation method
//     vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
//     vector<vector<int>> curr(2, vector<int>(k + 1, 0)); 
//     // Base Case
//     for(int buy = 0;buy <= 1;buy++){
//         for(int cap = 0; cap <= k;cap++){
//             ahead[buy][cap] = 0;
//         }
//     }
//     // if cap = 0;
//     for(int buy = 0; buy <= 1;buy++){
//         curr[buy][0] = 0;
//     }
//     for(int i = n - 1;i >= 0;i--){
//         for(int buy = 0; buy <= 1;buy++){
//             for(int cap = 1; cap <= k;cap++){
//                 if(buy == 1){
//                     curr[buy][cap] = max(-prices[i] + ahead[0][cap], ahead[1][cap]);
//                 }
//                 else{
//                     curr[buy][cap] = max(prices[i] + ahead[1][cap - 1], ahead[0][cap]);
//                 }
//             }
//         }
//         ahead = curr;
//     }
//     return ahead[1][k];
}
