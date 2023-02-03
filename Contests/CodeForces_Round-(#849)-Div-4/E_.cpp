#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int n = 100000005;
#define pb push_back

ll solve(int index, int change, vector<ll> &arr, vector<vector<ll>> &dp){

    int n = arr.size();

    if(index == n - 1){
        return arr[index];
    }

    if(dp[index][change] != -1e11){
        return dp[index][change];
    }

    ll sum = 0;

    // either reverse the sign.
    arr[index] = (-1ll * arr[index]);
    arr[index + 1] = (-1ll * arr[index + 1]);
    ll sum1 = (arr[index]) + solve(index + 1, 1, arr, dp);
    // While backtracking.
    arr[index] = (-1ll * arr[index]);
    arr[index + 1] = (-1ll * arr[index + 1]);

    // or don't reverse of the adjacent elements.
    ll sum2 = arr[index] + solve(index + 1, 0, arr, dp);

    return dp[index][change] = max(sum1, sum2);
}

void work(){
    // My Try : 
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for(auto &x : arr) cin >> x;
    // Recursion + memoisation.
    vector<vector<ll>> dp(n,vector<ll>(2, -1e11));
    // 0 - indicates no change.
    // 1 - indicates change.
    ll ans = solve(0, 0, arr, dp);
    cout << max(ans, dp[0][1]) << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


