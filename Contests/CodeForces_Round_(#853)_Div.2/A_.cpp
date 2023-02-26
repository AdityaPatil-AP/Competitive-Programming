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
    vector<ll> arr(n);
    for(auto &x : arr) cin >> x;

    sort(arr.begin(), arr.end());
    // if(__gcd(arr[0], arr[1]) <= 2){
    //     cout << "YES" << endl; 
    // }
    // else{
    //     cout << "NO" << endl;
    // }

    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            if(__gcd(arr[i], arr[j]) <= 2){
                cout << "YES" << endl; 
                return;
            }
        }
    }

    cout << "NO" << endl;
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

