#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod 1000000007

ll binpow(ll a, ll b, ll p){
    if(b == 0) return 1;
    ll t = binpow(a, b/2, p);
    if(b % 2) return (((a * t)%p)*t)%p;
    else return ((t * t) % p);
}


void work(){
    // My WRONG ATTEMPT
    // int n;
    // cin >> n;
    // vector<int> vec(n, 0);
    // vector<int> vec1(n, 0);
    // for(int i = 0;i < n;i++){
    //     cin >> vec[i];
    //     vec1[i] = vec[i];
    // }
    // ll ans = 0;
    // for(int i = 1;i < n - 1;i++){
    //     for(int j = vec[i], k = vec[i];;j--, k++){
    //         if(__gcd(j, vec[i - 1]) == 1 && __gcd(j, vec[i+1]) == 1){
    //             ans = (ans + (ll)(pow(2, abs(j - vec[i])))%mod)%mod;
    //             vec[i] = j;
    //             break;
    //         }
    //         else if(__gcd(k, vec[i - 1]) == 1 && __gcd(k, vec[i+1]) == 1){
    //             ans = (ans + (ll)(pow(2, abs(k - vec[i])))%mod)%mod;
    //             vec[i] = k;
    //             break;
    //         }
    //     }
    // }
    // cout << ans << endl;


    // Editor Solution - with my try
    // ll n; 
    // cin >> n;
    // vector<ll> vec(n, 0);
    // for(int i = 0;i < n;i++){
    //     cin >> vec[i];
    // }
    // ll k = 30; // K <= 50  n*K*K < (2 * (10^8))
    // vector<vector<ll>> dp(n, vector<ll> (2 * k + 1, LLONG_MAX));
    // for(int i = 0;i <= 2 * k;i++){
    //     dp[0][i] = pow(2, abs(i - k));
    // }
    // for(int i = 1;i < n;i++){
    //     for(int j = -k; j <= k;j++){
    //         for(int jj = -k;jj <= k;jj++){
    //             if(__gcd(vec[i] + j, vec[i - 1] + jj) != 1){
    //                 continue;
    //             }
    //             if(vec[i] + j < 0 && vec[i - 1] + jj < 0){
    //                 continue;
    //             }
    //             dp[i][j] = min(dp[i][j], dp[i - 1][jj] + pow(2, abs(j)));
    //         }
    //     }
    // }

    // Editor Solution or Setter's Solution
    // int n;
    // cin >> n;
    // int a[n];
    // for(int i = 0;i < n;i++){
    //     cin >> a[i];
    // }
    // int k = 23; // k <= 50
    // vector<vector<long long>> dp(k, vector<long long> (n, 1e18));
    // for(int i = 0;i < k;i++){
    //     int bi = a[0] + i - 16;
    //     if(bi < 0){
    //         continue;
    //     }
    //     dp[i][0] = min(dp[i][0], binpow(2, abs(a[0] - bi), 1e18));
    // }

    // for(int i = 1;i < n;i++){
    //     for(int j = 0;j < k;j++){
    //         int bi = a[i] + j - 16;
    //         if(bi < 0) continue;
    //         ll x = binpow(2, abs(bi - a[i]), 1e12);
    //         for(int l = 0;l < k;l++){
    //             int ci = a[i - 1] + l - 16;
    //             if(ci < 0){
    //                 continue;
    //             }
    //             if(__gcd(bi, ci) == 1){
    //                 dp[j][i] = min(dp[j][i], dp[l][i - 1] + x);                          
    //             }
    //         }
    //     }
    // }

    // ll ans = 1e18;
    // for(int i = 0;i < k;i++)
    //     ans = min(ans, dp[i][n - 1]);
    // cout << ans << endl;

    // Tester 1's Solution
    int n;
    cin >> n;
    vector<ll> vec(n);
    for(auto &x:vec){
        cin >> x;
    }
    const int k = 2;
    vector<vector<ll>> dp(n, vector<ll> ((2 * k) + 1, LLONG_MAX));
    for(int i = -k;i <= k;++i){
        dp[0][k + i] = 1LL << abs(i);
    }
    for(int i = 1;i < n;++i){
        for(int j = -k; j <= k;++j){
            for(int jj = -k;jj <= k;++jj){
                ll x = vec[i] + j, y = vec[i - 1] + jj;
                if(__gcd(x, y) > 1) continue;
                if(dp[i - 1][jj + k] == LLONG_MAX) continue;
                if(x < 0 && y < 0) continue;
                dp[i][j + k] = min(dp[i][j + k], dp[i - 1][jj + k] + (1LL << abs(j)));
            }
        }
    }

    ll ans = LLONG_MAX;
    for(int i = 0;i <= 2 * k;i++)
        ans = min(ans, dp[n - 1][i]);
    // assert(ans < LLONG_MAX);
    cout << (ans%mod) << endl;
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