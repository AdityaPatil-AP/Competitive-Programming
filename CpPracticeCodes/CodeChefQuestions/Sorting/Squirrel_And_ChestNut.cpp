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

ll helper(vector<ll> &ti, vector<ll> &pi, ll n, ll mid){
    ll ans = 0;
    vector<ll> temp(ti.size(), 0);
    for(int i = 0;i < ti.size();i++){
        temp.push_back((mid >= ti[i]) ? (((mid - ti[i])/pi[i]) + 1) : 0);
    }
    sort(temp.begin(), temp.end());
    for(int i = temp.size() - 1, count = 0;count < n && i >= 0;count++, i--){
        ans += temp[i];
    }
    return ans;
}

void work(){
    // My Try :
    // Squirrel And ChestNut.
    // Combination of Binary Search and Sorting.
    ll m, n, k;
    cin >> m >> n >> k;
    vector<ll> ti(m, 0);
    for(auto &x : ti) cin >> x;
    vector<ll> pi(m, 0);
    for(auto &x : pi) cin >> x;
    ll start = 0, end = 1e10;
    while(start < end){
        ll mid = (start + (end - start)/2);
        ll ans = helper(ti, pi, n, mid);
        if(ans < k)
            start = mid + 1;
        else
            end = mid;
    }
    cout << start << endl;
    return;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\CpPracticeCodes\\CodeChefQuestions\\output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    // cout << "Hello World" << endl;
    for(int i = 0;i < testcase;i++){
        work();
    }
    return 0;
}


