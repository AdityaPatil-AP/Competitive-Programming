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
    ll n, x;
    cin >> n >> x; 
    ll sum = 0;
    // l -> first index where non-multiple of x is present.
    // r -> last index where non-multiple of x is present.
    // l -> will be updated only once.
    // r -> will be updated every time.
    ll l = -1, r = 0;

    for(int i = 0;i < n;i++){
        ll a;
        cin >> a;
        if(a % x){
            if(l == -1) l = i;
            r = i;
        }
        sum += a;
    }

    if(sum % x != 0) cout << n << endl;
    else if(l == -1){
        // indicates no non-multiple of x present.
        cout << -1 << endl;
    }
    else{
        // There were non-multiples of x present in the array.
        // We just have to figure out whether to remove the non-multiple 
        // of x present in the prefix or suffix.
        cout << max(n - (l + 1), r) << endl;
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

