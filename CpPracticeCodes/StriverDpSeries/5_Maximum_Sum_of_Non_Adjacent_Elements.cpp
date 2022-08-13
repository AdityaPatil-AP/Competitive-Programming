#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int maxSumNA(int index, vector<int> &vec, vector<int> &dp){
    // Base Cases and Edge Cases 
    if(index == 0){
        return vec[index];
    }

    if(index < 0){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }
    int pick = vec[index] + maxSumNA(index - 2, vec, dp);
    int notpick = maxSumNA(index - 1, vec, dp);

    return dp[index] = max(pick, notpick);
}

// My codestudion submission

// long long int solve(vector<int> &vec){
//     long long int prev2 = 0;
//     long long int prev1 = vec[0];
//     for(int i = 1;i < vec.size();i++){
//         long long int take = vec[i];
//         if(i > 1)
//             take += prev2;
//         long long int nottake = prev1;
//         long long int curri = max(take, nottake);
//         prev2 = prev1;
//         prev1 = curri;
//     }
//     return prev1;
// }

// long long int houseRobber(vector<int>& valueInHouse)
// {
//     // Write your code here.
//     int size = valueInHouse.size();
//     vector<int> temp1, temp2;
//     if(size == 1)
//         return valueInHouse[0];
//     for(int i = 0;i < size;i++){
//         if(i != 0) temp1.push_back(valueInHouse[i]);
//         if(i != (size - 1)) temp2.push_back(valueInHouse[i]);
//     }
//     // Recursion and Memoisation
//     long long int ans1 = solve(temp1);
//     long long int ans2 = solve(temp2);
//     return max(ans1, ans2);
// }

void work(){
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for(auto &x:vec){
        cin >> x;
    }

    // Recursion + Memoization
    // vector<int> dp(n, -1);
    // int ans = maxSumNA(n - 1, vec, dp);
    // cout << ans << endl;

    // Space Optimisation from tabulation
    int prev, prev2;
    prev = vec[0];
    prev2 = 0; // negative;
    for(int i = 1;i < n;i++){
        // take 
        int take = vec[i];
        if(i > 1){
            take += prev2;
        }
        int nottake = prev;
        int curri = max(take, nottake);
        prev2 = prev;
        prev = curri;
    }
    cout << prev << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\StriverDpSeries\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\StriverDpSeries\\output.txt", "w", stdout);
    #endif
    int testcases = 1;
    cin >> testcases;
    for(int i = 0;i < testcases;i++)
        work();
    return 0;
}