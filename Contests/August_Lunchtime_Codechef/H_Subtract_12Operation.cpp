#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define int long long int

int f(int ind, vector<int> &arr, vector<int> &dp){
    // Base Case
    if(ind == 0){
        return 0;
    }
    if(dp[ind] != INT_MIN){
        return dp[ind];
    }
    // Explorations
    int take = INT_MAX, not_operate = f(ind - 1, arr, dp);
    int curr = abs(arr[ind]) + abs(arr[ind - 1]);
    int change = (abs(arr[ind] - 2) + abs(arr[ind - 1] - 1));
    if(abs(change) <= curr){
        arr[ind] -= 2;
        arr[ind - 1] -= 1;
        take = f(ind, arr, dp);
        // if(take > not_operate){
        //     arr[ind] += 2;
        //     arr[ind - 1] += 1;
        // }
    }
    return dp[ind] = min(not_operate, take);
}

void work(){
    // H. Subtract 12 Operations
    // int n;
    // cin >> n;
    // vector<int> arr(n, 0);
    // for(int i = 0;i < n;i++){
    //     cin >> arr[i];
    // }
    // vector<int> dp(n, INT_MIN);
    // int ans1 = f(n - 1, arr, dp);


    // Tabulation Format
    // Base Case
    // int n;
    // cin >> n;
    // vector<int> arr(n, 0);
    // for(int i = 0;i < n;i++){
    //     cin >> arr[i];
    // }

    // for(int ind = 1; ind <= n - 1;ind++){
    //     bool flag = true;
    //     while(flag){
    //         int curr = abs(arr[ind]) + abs(arr[ind - 1]);
    //         int change = (abs(arr[ind] - 2) + abs(arr[ind - 1] - 1));
    //         if(abs(change) <= curr){
    //             arr[ind] -= 2;
    //             arr[ind - 1] -= 1;
    //         }
    //         else{
    //             flag = false;
    //         }
    //     }
    // }

    // for(int i = 0;i < n;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    // int curr = abs(arr[i]) + abs(arr[i - 1]);
    // int change = (abs(arr[i] - 2) + abs(arr[i - 1] - 1));

    // for(int i = 0;i <= n - 2 && n > 1;i++){
    //     if(arr[i] <= arr[i + 1] && arr[i + 1] >= 2){
    //         // if(arr[i] <= 0 && arr[i + 1] == 1){
    //         //     continue;
    //         // }  
    //         int num = ((arr[i + 1])/2);
    //         arr[i] -= num;
    //         arr[i + 1] -= (2 * num);
    //     }
    //     else if(arr[i] == 1 && arr[i + 1] == 1){
    //         arr[i] = 0;
    //         arr[i + 1] = -1;
    //     }
    //     else{
    //         continue;
    //     }
    // }


    // int ans = 0;
    // for(int i = 0;i < n;i++){
    //     ans += abs(arr[i]);
    // }
    // cout << ans << endl;

    // Editorial Solution
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    for(int i = n - 1;i >= 1;i--){
        if(arr[i] > 0){
            int k = arr[i]/2;
            arr[i] -= 2 * k;
            arr[i - 1] -= k;
        }
    }

    for(int i = n - 1;i >= 1;i--){
        if(arr[i] > 0 && arr[i - 1] > 0){
            arr[i] -= 2;
            arr[i - 1] -= 1;
        }
    }
    int ans = 0;
    for(int i = 0;i < n;i++){
        ans += abs(arr[i]);
    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    int testcase = 1;
    cin >> testcase;
    for(int m = 1; m <= testcase;m++){
        work();
    }
    return 0;
}