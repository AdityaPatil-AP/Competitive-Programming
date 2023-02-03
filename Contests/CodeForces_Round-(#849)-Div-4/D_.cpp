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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    map<char, ll> mp;
    vector<ll> start(n, 0);
    ll count = 0;
    for(int i = 0;i < n;i++){
        if(mp[s[i]] == 0){
            count++;
        }
        else count--;
        mp[s[i]]++;
        start[i] = mp.size();
    }

    mp.clear();
    vector<ll> end(n, 0);
    count = 0;
    for(int i = n - 1;i >= 0;i--){
        if(mp[s[i]] == 0){
            count++;
        }
        else count--;
        mp[s[i]]++;
        end[i] = mp.size();
    }    
    
    ll ans = INT_MIN;
    for(int i = 0; i < (n - 1);i++){
        ans = max(ans, start[i] + end[i + 1]);
    }

    cout << ans << endl;
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


