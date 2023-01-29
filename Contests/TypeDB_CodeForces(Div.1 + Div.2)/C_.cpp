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

map<int, int> prime_factorization(int n) {
    map<int, int> mp;
    while (n % 2 == 0) {
        mp[2]++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            mp[i]++;
            n = n / i;
        }
    }
    if (n > 2)
        mp[n]++;
    return mp;
}

void work(){
    // My Try : 
    ll n, s;
    cin >> n >> s;
    vector<ll> arr(n);
    for(auto &x : arr) cin >> x;
    ll ans = 0;
    ll first = arr[0];
    for(int i = 1; i < arr.size() - 1;i++){
        
    }
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


