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

const int N = 10000005;
#define pb push_back

void work(){
    // GCD Length
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = pow(10, a - 1);
    ll y = 1;
    for(int i = 0;i < (b - c);i++){
        y = (y * 10) + 1;
    }
    for(int i = 0;i < c - 1;i++){
        y = (y * 10);
    }
    cout << x << " " << y << endl;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\input.txt","r", stdin);
    freopen("E:\\only one folder\\CompetitiveProgramming Github Repo\\Competitive-Programming\\Learning\\output.txt", "w", stdout);
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


