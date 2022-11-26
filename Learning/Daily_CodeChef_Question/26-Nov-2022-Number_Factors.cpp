#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int N = 1000000;
#define pb push_back

bool powerOf2(ll m){
    // ll n = __builtin_popcountll(m);
    // return n == 1;
    return !(m & (m - 1));
}

void work(){
    // Number of Factors.
    ll n;
    cin >> n;
    unordered_map<ll, ll> mp;
    for(int i = 0;i < n;i++){
        ll x;
        cin >> x;
        for(int i = 2;i * i <= x;i++){
            while(x % i == 0){
                mp[i]++;
                x = x/i;
            }
        }
        if(x > 1){
            mp[x]++;
            x = 1;
        } 
    }
    ll ans = 1;
    for(auto it : mp){
        ans = ans * (it.second + 1);
    }
    cout << ans << endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
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


