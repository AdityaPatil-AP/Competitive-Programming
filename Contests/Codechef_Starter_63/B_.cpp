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

void work(){
    // My Try :
    // 
    ll n;
    cin >> n;
    vector<ll> arr(n, 0);
    for(auto &x: arr) cin >> x;
    map<int, int> mp;   
    set<int> st;
    for(int i = 0;i < n;i++){
        mp[arr[i]]++;
        st.insert(arr[i]);
    }
    int maxsum = 0;
    for(auto it : st){
        ll curr = mp[it];
        if(st.find(it + 1) != st.end()){
            if((it ^ (it + 1)) <= 1){
                curr += mp[it + 1]; 
            }
        }
        maxsum = max((ll)maxsum, curr);
    }
    // cout << maxsum << endl;
    cout << n - maxsum << endl;
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


