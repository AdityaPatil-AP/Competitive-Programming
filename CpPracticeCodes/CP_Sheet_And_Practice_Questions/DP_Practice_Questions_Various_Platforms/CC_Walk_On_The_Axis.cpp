#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;



void work(){
    // My Solution
    // long long int n;
    // cin >> n;
    // cout << ((n * (n + 1))/2 + n) << endl;

    // Editors Solution - dp approach - This gives us time limit
    // exceeded
    long long int n;
    cin >> n;
    vector<long long int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 2;
    for(int i = 2;i <= n;i++){
        dp[i] = (2*i + 1) + dp[i - 2];
    }
    cout << dp[n] << endl;
}

int main(){
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


