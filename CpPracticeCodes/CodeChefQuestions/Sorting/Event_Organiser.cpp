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

bool comp(vector<ll> &a1, vector<ll> &a2){
    if(a1[1] <= a2[1]) return true;
    return false;
}

ll ans = 0;

ll helper(ll end, vector<vector<ll>> &events, ll index, vector<vector<ll>> &dp){
    if(index >= events.size()){
        return 0;
    }
    if(dp[index][end] != -1){
        return dp[index][end];
    }
    ll ans1 = 0, ans2 = 0;
    // either I can perform this activity
    if(end <= events[index][0]){
        ans1 = events[index][2] + helper(events[index][1], events, index + 1, dp);
    }
    // Or Don't take the current order.
    ans2 = helper(end, events, index + 1, dp);
    ans = max(max(ans1, ans2), ans);
    return dp[index][end] = max(ans1, ans2);
}

void work(){
    // My Try :
    // Event Organiser.
    ll n;
    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(3, 0ll));
    for(int i = 0;i < n;i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    sort(arr.begin(), arr.end(), comp);
    // Using Recursion to choose which activities to opt for.
    // Out of all such activities chosen find the sequence which gives
    // us the maximum Compensation.
    ll end = 0, index = 0; // index denotes the current event we are performing.
    // end denotes the end Time of the Previous event chosen.
    // This recursion may lead to Time Limit Exceeded.
    // So We will memoise it.
    ans = 0;
    vector<vector<ll>> dp(2*n, vector<ll>(100, -1));
    helper(end, arr, index, dp);
    cout << ans << endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    // cout << "Hello World" << endl;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


