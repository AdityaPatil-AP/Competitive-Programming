#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

pair<int,bool> f(int index, int x, vector<int> &arr, vector<pair<int,bool>> &dp){
    if(index == 1){
        int maxi = INT_MIN;
        int sum1 = (arr[index]) ^ (arr[index - 1]);
        int sum2 = (arr[index] + x) ^ (arr[index - 1]);
        int sum3 = (arr[index]) ^ (arr[index - 1] + x);
        int sum4 = (arr[index] + x) ^ (arr[index - 1] + x);
        maxi = max(max(sum1, sum2), max(sum3, sum4));
        if(maxi == sum2 || maxi == sum4){
            return{maxi, true};
        }
        return {maxi, false};
    }
    if(dp[index].first != -1){
        return dp[index];
    }
    // Explore all the paths
    int maxi = INT_MIN;
    pair<int, bool> smallAns = f(index - 1, x, arr, dp);
    if(smallAns.second == true){
        int sum1  = max(maxi, ((arr[index]) ^ (arr[index - 1] + x)) + f(index - 1, x, arr, dp).first);
        int sum2  = max(maxi, ((arr[index] + x) ^ (arr[index - 1] + x)) + f(index - 1, x, arr, dp).first);
        maxi = max(sum1, sum2);
        if(maxi == sum2){
            return dp[index] = {maxi, true};
        }
    }
    else{
        int sum1 = max(maxi, ((arr[index]) ^ (arr[index - 1])) + f(index - 1, x, arr, dp).first);
        int sum2 = max(maxi, ((arr[index] + x) ^ (arr[index - 1])) + f(index - 1, x, arr, dp).first);
        maxi = max(sum1, sum2);
        if(maxi == sum2){
            return dp[index] = {maxi, true};
        }

    }
    return {maxi, false};
}

void work(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n, 0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    vector<pair<int, bool>> dp(n, {-1, 0});
    cout << f(n - 1, x, arr, dp).first << endl;
}

int main(){
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