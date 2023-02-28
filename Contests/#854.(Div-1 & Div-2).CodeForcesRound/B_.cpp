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
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);

    // First we have to find the smallest number we 
    // can get till.


    for(auto &x : arr) cin >> x;
    // If all the elements are equal. 
    // Then the answer is 0.
    multiset<pair<int, int>> ms;

    for(int i = 0;i < n;i++){
        ms.insert({arr[i], i + 1});
    }
    vector<pair<int, int>> ans;
    int m = 0;
    while(true){
        int start = (*ms.begin()).first;
        auto last = ms.rbegin();
        int end = (*last).first;
        // cout << start << " " << end << endl;
        if(start == end){
            break;
        }
        if(start == 1 && end != 1){
            cout << -1 << endl;
            return;
        }
        int starti = (*ms.begin()).second;
        int endi = (*ms.rbegin()).second;
        ans.push_back({endi, starti});
        int curr = ceil((double)end/start);
        auto it = *last;
        ms.erase(it);
        ms.insert({curr, endi});
        m++;
    }
    cout << m << endl;
    for(auto it : ans){
        cout << it.first << " " << it.second << endl;
    }

    return;
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

