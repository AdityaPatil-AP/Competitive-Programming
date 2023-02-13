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
    bool found = false;
    while(l < r){
        ll sm = *min_element(arr.begin() + l, arr.begin() + r + 1);
        ll la = *max_element(arr.begin() + l, arr.begin() + r + 1);
        if(sm == min(arr[l], arr[r]) && la == max(arr[l], arr[r])){
            l++;
            r--;
        }
        else if(sm == arr[l] || la == arr[l]){
            l++;
        }
        else if(la == arr[r] || sm == arr[r]){
            r--;
        }
        else{
            found = true;
            break;
        }
    }
    if(found){
        cout << l + 1 << " " << r + 1 << endl;
    }
    else cout << -1 << endl;
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

