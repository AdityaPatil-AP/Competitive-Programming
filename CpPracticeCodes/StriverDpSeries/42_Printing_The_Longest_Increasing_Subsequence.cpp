#include <bits/stdc++.h>
int f(int ind, int prev_ind, int *arr, int n, vector<vector<int>> &dp){
    // Base Case
    if(ind == n){
        return 0;
    }
    if(dp[ind][prev_ind + 1] != -1){
        return dp[ind][prev_ind + 1];
    }
    // Explorations
    // don't take this element
    int len1 = f(ind + 1, prev_ind, arr, n, dp);
    int len2 = INT_MIN;
    if(prev_ind == -1  || arr[ind] > arr[prev_ind]){
        len2 = 1 + f(ind + 1, ind, arr, n, dp);
    }
    return dp[ind][prev_ind + 1] = max(len1, len2);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    // Recursion and Memoization
    // This gives runtime error because the of the constraints exceed 2 * 10 ^ 8;
//     vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//     return f(0, -1, arr, n, dp);
    
    // Tabulation
//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//     for(int i = 0;i <= n;i++){
//         dp[n][i] = 0;
//     }
//     for(int i = n - 1;i >= 0;i--){
//         for(int j = i - 1; j >= -1;j--){
//             int not_take = dp[i + 1][j + 1];
//             int take = INT_MIN;
//             if(j == -1 || arr[i] > arr[j]){
//                 take = 1 + dp[i + 1][i + 1];
//             }
//             dp[i][j + 1] = max(take, not_take);
//         }
//     }
//     return dp[0][-1 + 1];
    
    // Space Optimisation
//     vector<int> next(n + 1, 0);
//     vector<int> curr(n + 1, 0);
//     for(int i = 0;i <= n;i++){
//         next[i] = 0;
//     }
//     for(int ind = n - 1;ind >= 0;ind--){
//         for(int prev_ind = ind - 1;prev_ind >= -1;prev_ind--){
//             int not_take = next[prev_ind + 1];
//             int take = INT_MIN;
//             if(prev_ind == -1 || arr[ind] > arr[prev_ind] ){
//                 take = 1 + next[ind + 1];
//             }
//             curr[prev_ind + 1] = max(take, not_take);
//         }
//         next = curr;
//     }
//     return next[-1 + 1];

       // O(n) Space complexity answer
    vector<int> dp(n, 1), hash(n, 1);
    int lastIndex = 0;
    int maxi = 1;
    for(int i = 0;i < n;i++){
        hash[i] = i;
        for(int prev = 0;prev < i;prev++){
            if(arr[i] > arr[prev]){
                if(1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> lis;
    lis.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        lis.push_back(arr[lastIndex]);
    }
    reverse(lis.begin(), lis.end());
    for(auto it : lis){
        cout << it << " ";
    }
    cout << endl;
    return maxi;
}
