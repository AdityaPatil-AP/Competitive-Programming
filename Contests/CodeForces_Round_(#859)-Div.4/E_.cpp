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

    // int n;
    // cin >> n;
    // vector<int> pref(n + 1);
    // for (int i=0; i<n; i++) {
    //     int a;
    //     cin >> a;
    //     pref[i+1] = pref[i] + a;
    // }
 
    // int l = 1, r = n + 1;
    // while (l < r) {
    //     int m = (l + r) / 2;
    //     cout << "? " << m;
    //     for (int i=1; i<=m; i++)
    //         cout << " " << i;
    //     cout << endl;
    //     int ret;
    //     cin >> ret;
    //     if (ret > pref[m])
    //         r = m;
    //     else
    //         l = m + 1;
    // }
    // cout << "! " << l << endl;

    ll n;
    cin >> n;
    vector<ll> pref(n + 1);
    pref[0] = 0;
    for(int i = 1;i <= n;i++){
        ll a;
        cin >> a;
        pref[i] = pref[i - 1] + a;
    }

    ll l = 1, r = n, ans = 1;
    while(l <= r){
        ll mid = (l + (r - l)/2);
        cout << "? " << (mid - l + 1) << " ";
        for(int i = l;i <= mid;i++){
            cout << i << " ";
        }
        cout << endl << flush;
        ll ret;
        cin >> ret;
        if(ret == (pref[mid] - pref[l - 1])){
            l = mid + 1;
        }
        else{
            r = mid - 1;
            ans = mid;
        }
    }

    cout << "! " << ans << endl << flush;
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


