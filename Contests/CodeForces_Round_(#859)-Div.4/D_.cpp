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

    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(auto &x : arr) cin >> x;
    
    vector<ll> prefixSum(n, 0);
    prefixSum[0] = arr[0];
    for(int i = 1;i < n;i++){
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    while(q--){
        ll l, r, k;
        cin >> l >> r >> k;

        l--, r--;

        ll totalSum = prefixSum[n - 1];

        ll currSum = 0;

        if(l == 0) currSum += prefixSum[r];
        else currSum += (prefixSum[r] - prefixSum[l - 1]);

        ll change = (k * (r - l + 1)) - currSum;

        if((totalSum + change) % 2 == 1){
            cout << "YES" << endl;
        }        
        else{
            cout << "NO" << endl;
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


