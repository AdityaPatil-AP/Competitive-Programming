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

bool allEqual(vector<ll> &arr){
    int first = arr[0];
    for(int i = 1;i < arr.size();i++){
        if(arr[i] != first) return false;
    }

    return true;
}

void work(){
    // My try :
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n, 0);
    for(auto &x : arr) cin >> x;
    vector<ll> cold(k, 0);
    for(auto &x : cold) cin >> x;
    vector<ll> hot(k, 0);
    for(auto &x : hot) cin >> x;
    
    ll ans = 0;
    int time = 0;
    int time1 = 0;
    int time2 = 0;
    int i = 0;
    while(true){
        int fmt = 
        if(time1 <= time){

        }

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

