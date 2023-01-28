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
    vector<vector<ll>> mat(n, vector<ll>(n - 1, 0));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n - 1;j++){
            cin >> mat[i][j];
        }
    }
    ll prev = 0, curr = 0;
    map<ll, ll> mp;
    for(int i = 0;i < n;i++){
        mp[mat[i][0]]++;
    }
    for(auto it : mp){
        if(it.second == n - 1){
            prev = it.first;
        }
        else{
            curr = it.first;
        }
    }

    vector<ll> ans;
    ans.push_back(prev);
    ans.push_back(curr);
    prev = curr;
    for(int j = 1;j < n - 1;j++){
        for(int i = 0;i < n;i++){
            if(mat[i][j] != prev){
                curr = mat[i][j];
            }
        }
        ans.push_back(curr);
        prev = curr;
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


