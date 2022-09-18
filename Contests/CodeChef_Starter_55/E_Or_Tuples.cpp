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
    // My Try : Wrong 
    // int p, q, r;
    // cin >> p >> q >> r;
    // int allOr = ((p|q)|r);
    // cout << allOr << endl;
    // int val = floor(log2(allOr));
    // int k = 0;
    // if(p != 0){
    //     k += (val - floor(log2(p ^ (allOr))));
    // }
    // if(q != 0){
    //     k += (val - floor(log2(q ^ (allOr))));
    // }
    // if(r != 0){
    //     k += (val - floor(log2(r ^ (allOr))));
    // }
    // cout << pow(2, k) << endl;

    // We are given p, q, r and we have to find the possible 
    // combinations for a, b, c.
    int p, q, r;
    cin >> p >> q >> r;
    // let's go through bit by bit.
    ll ans = 1;
    for(int i = 0;i < 20;i++){
        int cnt = 0;
        cnt += (p&(1 << i)) > 0;
        cnt += (q&(1 << i)) > 0;
        cnt += (r&(1 << i)) > 0;
        if(cnt == 1) ans = 0;
        if(cnt == 3) ans *= 4; 
    }
    cout << ans << endl;
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


