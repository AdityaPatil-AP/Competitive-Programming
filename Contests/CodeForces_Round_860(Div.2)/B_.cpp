#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <chrono>
#include <string>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

// Macros list.


#define mod 1000000007
#define ll long long int
#define PRIME 1000000007

const int n = 100000005;
#define pb push_back

// GitHub Repository for Large Code Implementations.


// After solving the problem, look for solution of higher rated person.
// Understand what optimisation he has done.

// Prove your problem correctness. Why only this work here?

// See the constraints, and solve it, don't over optimise.

// Always read the editorial for an unsolved problem.

// You are almost there, Don't stop now. Great Thing takes time.
// If you think, there is another idea that may work, go for it as well!!

void work(){
    // My Try :
    // A) 

    ll m;
    cin >> m;
    vector<vector<ll>> a;
    ll temp = m;
    while(temp--){
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(auto &x : arr){
            cin >> x;
        }
        a.push_back(arr);
    }

    map<ll, ll> mp;
    vector<ll> ans;
    bool answer = true;
    for(int i = m - 1;i >= 0;i--){
        vector<ll> curr = a[i];
        bool found = false;
        for(int j = 0;j < curr.size();j++){
            if(mp[curr[j]] == 0 && !found){
                ans.push_back(curr[j]);
                found = true;
            }
            mp[curr[j]]++;
        }

        if(!found){
            answer = false;
            break;
        }
    }
    
    if(!answer){
        cout << "-1" << endl;
    }
    else{
        reverse(ans.begin(), ans.end());
        for(int i = 0;i < ans.size();i++){
            cout << ans[i] << " ";
        }
        cout << endl;
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


