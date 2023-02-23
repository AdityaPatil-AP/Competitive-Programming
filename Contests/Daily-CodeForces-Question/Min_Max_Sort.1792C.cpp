#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
#include <numeric>
// #include <boost/math/common_factor.hpp>
using namespace std;
// using namespace std::chrono;

#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int n = 100000005;
#define pb push_back

ll lcm(ll a, ll b){
    ll g = __gcd(a, b);
    return ((a * b)/g);
}

void work(){
    // My try :
    ll n;
    cin >> n;
    vector<ll> pos(n + 1);
    for(int i = 0;i < n;i++){
        ll x;
        cin >> x;
        pos[x] = i;
    }

    int l = (n + 1)/2, r = (n + 2)/2;
    
    while(l > 0 && ((l == r) || (pos[l] < pos[l + 1] && pos[r - 1] < pos[r]))){
        l--;
        r++;
    }
    cout << (n - r + l + 1)/2 << endl;
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

