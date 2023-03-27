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

    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> b(n);
    for(auto &x : arr) cin >> x;
    for(auto &x : b) cin >> x;

    for(int i = 0;i < n;i++){
        if(arr[i] > b[i]){
            swap(arr[i], b[i]);
        }
    }

    ll max_a = *(max_element(arr.begin(), arr.end()));
    ll max_b = *(max_element(b.begin(), b.end()));

    if(max_a == arr[n - 1] && max_b == b[n - 1]){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
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


