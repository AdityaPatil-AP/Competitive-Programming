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
    vector<ll> arr(n, 0);
    for(auto &x : arr) cin >> x;

    ll l = 0, r = n-1;
    int mn = 1, mx = n;
    bool found = false;
    while(l < r){
        if(arr[l] == mn){
            l++;
            mn++;
        }
        else if(arr[r] == mx){
            r--;
            mx--;
        }
        else if(arr[l] == mx){
            l++;
            mx--;
        }
        else if(arr[r] == mn){
            r--;
            mn++;
        }
        else{
            cout << l + 1 << " " << r + 1 << endl;
            found = true;
            break;
        }
    }
    if(!found) cout << -1 << endl;
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

