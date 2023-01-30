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

const int N = 200005;
long long f[N][2], x[N], y[N];

void work(){
    // Upsolving.  
    int i, n, s, j;
    cin >> n >> s;
    for(int i = 1;i <= n;i++){
        cin >> j;
        if(i == 1 || i == n) x[i] = y[i] = j;
        else if(j <= s) x[i] = 0, y[i] = j;
        else x[i] = s, y[i] = j - s;
    }
    f[1][0] = f[1][1] = 0;
    for(int i = 2;i <= n;i++){
        f[i][0] = min(f[i - 1][0] + y[i - 1] * x[i], f[i - 1][1] + x[i - 1] * x[i]);
        f[i][1] = min(f[i - 1][0] + y[i - 1] * y[i], f[i - 1][1] + x[i - 1] * y[i]);
    }

    cout << f[n][1] << endl;

    // My Try : 
    // ll n, s;
    // cin >> n >> s;
    // vector<ll> arr(n);
    // for(auto &x : arr) cin >> x;
    // ll ans = 0;
    // ll first = arr[0];
    // for(int i = 1; i < arr.size() - 1;i++){
    //     ll second = s;
    //     ans += (first * second);
    //     first = (arr[i] - s);
    // }
    // ans += (first * arr[n - 1]);
    // cout << ans << endl;
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


