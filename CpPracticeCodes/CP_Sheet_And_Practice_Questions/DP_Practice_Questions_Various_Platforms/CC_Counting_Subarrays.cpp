#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
#define int long long

void work(){
    // Editor Solution
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    // dp[i] - indicates the count of subarrays where the right bound is i.
    vector<int> dp(n, 0);
    dp[0] = 1;
    int ans = 1;
    for(int i = 1;i < n;i++){
        if(arr[i] >= arr[i - 1]){
            dp[i] = dp[i - 1] + 1;
        }
        else{
            dp[i] = 1;
        }
        ans+= dp[i];
    }
    cout << ans << endl;
}

int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CP_Sheet_And_Practice_Questions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CP_Sheet_And_Practice_Questions\\output.txt", "w", stdout);
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


