#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define lld long long double

void work(){
    // My wrong Solution
    // ll x, y;
    // cin >> x >> y;
    // ll start;
    // ll flag = 0;
    // if(x%2 == 0){
    //     start = x/2;
    // }
    // else{
    //     start = x/2 + 1;
    // }
    // for(int i = start + 1;i <= floor(sqrt(y));i++){
    //     if(y % i == 0){
    //         flag = i; 
    //         break;
    //     }
    // }
    // if(flag == 0){
    //     cout << "-1" << endl;
    //     return;
    // }
    // if(x % 2 == 0){
    //     cout << x/2 << " " << x/2 << endl;
    // }
    // else{
    //     cout << x/2 << " " << x/2 + 1 << endl;
    // }
    // if(y < x/2){
    //     cout << 1 << " " << y << endl;
    //     return;
    // }
    // cout << flag << " " << y/flag << endl;
    // return; 

    // Editorial Solution
    ll x, y;
    cin >> x >> y;
    ll a = x/2;
    ll b = x/2;
    if(x % 2 != 0){
        ++b;
    }
    for(ll i = 1;i <= floor(sqrt(y));i++){
        if(y % i != 0){
            continue;
        }
        ll j = y/i;
        if(i > b || j< a){
            cout << a << " " << b << endl;
            cout << i << " " << j << endl;
            return; 
        }
    }
    cout << -1 << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Contests\\output.txt", "w", stdout);
    #endif
    int testcase = 1;
    cin >> testcase;
    for(int m = 1; m <= testcase;m++){
        work();
    }
    return 0;
}