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
    // My Try : Correct
    ll n;
    cin >> n;
    vector<ll> ai(n, 0);
    for(auto &x : ai) cin >> x;
    vector<ll> bi(n, 0);
    for(auto &x : bi) cin >> x;

    vector<ll> rem(n, 0);
    vector<ll> count(n, 0);

    vector<ll> pref(n, 0);
    pref[0] = bi[0];

    for(int i = 1;i < n;i++){
        pref[i] = bi[i] + pref[i - 1];
    }

    for(int i = 0;i < n;i++){

        ll curr = ai[i];
        if(i > 0) curr += pref[i - 1];

        ll j = upper_bound(pref.begin(), pref.end(), curr) - pref.begin();
        j--;
        if(j < i){
            if(j >= 0) rem[j + 1] += curr - pref[j]; 
            else rem[j + 1] += ai[i];
            // cout << rem[j + 1] << endl;
        }
        if(j >= i){
            count[i] += 1;
            if(j + 1 < n) count[j + 1] -= 1;
            if(j + 1 < n){
                rem[j + 1] += (curr - pref[j]);
            } 
        }
    }

    // count ko manage karo.
    for(int i = 1;i < n;i++){
        count[i] += (count[i - 1]);
    }

    vector<ll> ans(n, 0);

    for(int i = 0;i < n;i++){
        // cout << count[i] << " " << bi[i] << " " << rem[i] << endl;
        // cout << rem[i] << endl;
        ans[i] = (count[i] * bi[i]) + rem[i];
    }

    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
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

